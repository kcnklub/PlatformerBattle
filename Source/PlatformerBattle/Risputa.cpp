// Fill out your copyright notice in the Description page of Project Settings.

#include "PlatformerBattle.h"
#include "Risputa.h"
#include "RisputaBasicAttack.h"

ARisputa::ARisputa()
{
  Reticle = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Reticle"));


  Reticle->AttachTo(RootComponent);
  Reticle->SetOnlyOwnerSee(true);
}

void ARisputa::SetupPlayerInputComponent(class UInputComponent * InputComponent)
{
  Super::SetupPlayerInputComponent(InputComponent);

  InputComponent->BindAction("Attack", IE_Pressed, this, &ARisputa::Attack);
  bCanBeDamaged = true;
}

void ARisputa::Tick(float DeltaSeconds)
{
  Super::Tick(DeltaSeconds);
  
  if (GetCharacterMovement()->IsFalling())
  {
    Reticle->SetFlipbook(AirBornReticle);
  }
  else
  {
    Reticle->SetFlipbook(GroundReticle);
  }

  if (bIsFacingRight)
  {
    Reticle->RelativeLocation = FVector(-RangeOfBasic, 0.0f, 0.0f);
  }
  else
  {
    Reticle->RelativeLocation = FVector(RangeOfBasic, 0.0f, 0.0f);
  }
}

void ARisputa::Attack()
{
  if (BasicAttack != NULL)
  {
    BasicAttack->GetDefaultObject<ARisputaBasicAttack>()->setIsPlayerAirborn(GetCharacterMovement()->IsFalling());
    BasicAttack->GetDefaultObject<ARisputaBasicAttack>()->setOwningController(Controller);
    FVector SpawnLocation = GetActorLocation();

    if (bIsFacingRight)
    {
      SpawnLocation += FVector(RangeOfBasic, 0.0f, 0.0f);
    }
    else
    {
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
