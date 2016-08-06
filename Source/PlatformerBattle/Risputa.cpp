// Fill out your copyright notice in the Description page of Project Settings.

#include "PlatformerBattle.h"
#include "Risputa.h"
#include "RisputaBasicAttack.h"

ARisputa::ARisputa()
{
  Reticle = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Reticle"));
  bIsLockedOrientation = false;

  Reticle->AttachTo(RootComponent);
  Reticle->SetOnlyOwnerSee(true);
}

void ARisputa::SetupPlayerInputComponent(class UInputComponent * InputComponent)
{
  Super::SetupPlayerInputComponent(InputComponent);

  InputComponent->BindAction("Attack", IE_Pressed, this, &ARisputa::Attack);
  InputComponent->BindAction("LockCharacterOrientation", IE_Pressed, this, &ARisputa::LockOrientation);
  InputComponent->BindAction("LockCharacterOrientation", IE_Released, this, &ARisputa::LockOrientation);
  InputComponent->BindAction("AbilityOne", IE_Pressed, this, &ARisputa::Teleport);
}

void ARisputa::Tick(float DeltaSeconds)
{
  Super::Super::Tick(DeltaSeconds);


  UpdateCharacter();
  
  /////////////////////////////////////////////////////////
  //Update reticle
	FHitResult HitData;
  if (UStaticFunctionLibrary::Trace(GetWorld(), this, Reticle->GetComponentLocation(), Reticle->GetComponentLocation() + GroundCheck, HitData))
  {
    Reticle->SetFlipbook(GroundReticle);
  }
  else
  {
    Reticle->SetFlipbook(AirBornReticle);
  }

  if (bIsFacingRight)
  {
	if (UStaticFunctionLibrary::Trace(GetWorld(), this, GetActorLocation(), GetActorLocation() + FVector(RangeOfBasic, 0.f, 0.f), HitData))
	{
		Reticle->RelativeLocation = FVector(-HitData.Distance, 0.f, 0.f);
	}
	else
		Reticle->RelativeLocation = FVector(-RangeOfBasic, 0.0f, 0.0f);
  }
  else
  {
	  if (UStaticFunctionLibrary::Trace(GetWorld(), this, GetActorLocation(), GetActorLocation() + FVector(-RangeOfBasic, 0.f, 0.f), HitData))
	  {
		  Reticle->RelativeLocation = FVector(HitData.Distance, 0.f, 0.f);
	  }
	  else
		  Reticle->RelativeLocation = FVector(RangeOfBasic, 0.0f, 0.0f);
  }
  /////////////////////////////////////////////////////////

}

void ARisputa::Attack()
{
  if (BasicAttack != NULL)
  {
    FVector SpawnLocation = GetActorLocation();
		FHitResult HitData;

    if (bIsFacingRight)
    {
			if (UStaticFunctionLibrary::Trace(GetWorld(), this, GetActorLocation(), GetActorLocation() + FVector(RangeOfBasic, 0.f, 0.f), HitData))
				SpawnLocation += FVector(HitData.Distance, 0.f, 0.f);
			else
				SpawnLocation += FVector(RangeOfBasic, 0.0f, 0.0f);
    }
    else
    {
			if (UStaticFunctionLibrary::Trace(GetWorld(), this, GetActorLocation(), GetActorLocation() + FVector(-RangeOfBasic, 0.f, 0.f), HitData))
				SpawnLocation += FVector(-HitData.Distance, 0.f, 0.f);
			else
				SpawnLocation += FVector(-RangeOfBasic, 0.0f, 0.0f);
    }

    Attacking.Broadcast(CurrAttacking);

    UWorld * const World = GetWorld();
    if (World)
    {
      World->SpawnActor<ARisputaBasicAttack>(BasicAttack, SpawnLocation, FRotator(0.0f, 0.0f, 0.0f));
    }
  }
}

void ARisputa::UpdateCharacter()
{
	const FVector PlayerVelocity = GetVelocity();
	float TravelDirection = PlayerVelocity.X;
	
	if (!bIsLockedOrientation)
	{
		if (TravelDirection < 0.0f)
		{
			GetSprite()->RelativeRotation = FRotator(0.0, 0.0f, 0.0f);
			bIsFacingRight = false;
		}
		else if (TravelDirection > 0.0f)
		{
			GetSprite()->RelativeRotation = FRotator(0.0, 180.0f, 0.0f);
			bIsFacingRight = true;
		}
	}
}
void ARisputa::LockOrientation()
{
	bIsLockedOrientation = !bIsLockedOrientation;
}

void ARisputa::Teleport()
{
	FHitResult HitData;
	Teleporting.Broadcast(bIsTeleporting);
	if (bIsFacingRight)
	{
		if (UStaticFunctionLibrary::Trace(GetWorld(), this, GetActorLocation(), GetActorLocation() + FVector(RangeOfBasic, 0.f, 0.f), HitData))
			SetActorLocation(GetActorLocation() + FVector(HitData.Distance, 0.0f, 0.0f));
		else
			SetActorLocation(GetActorLocation() + FVector(RangeOfBasic, 0.0f, 0.0f));
	}
	else
	{
		if (UStaticFunctionLibrary::Trace(GetWorld(), this, GetActorLocation(), GetActorLocation() + FVector(-RangeOfBasic, 0.f, 0.f), HitData))
			SetActorLocation(GetActorLocation() - FVector(HitData.Distance, 0.0f, 0.0f));
		else
			SetActorLocation(GetActorLocation() - FVector(RangeOfBasic, 0.0f, 0.0f));
	}
}