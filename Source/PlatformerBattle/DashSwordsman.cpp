// Fill out your copyright notice in the Description page of Project Settings.

#include "PlatformerBattle.h"
#include "DashSwordsman.h"
#include "StaticFunctionLibrary.h"
#include "Engine.h"

void ADashSwordsman::SetupPlayerInputComponent(class UInputComponent * InputComponent)
{
  Super::SetupPlayerInputComponent(InputComponent);

  InputComponent->BindAction("Attack", IE_Pressed, this, &ADashSwordsman::Attack);
}

void ADashSwordsman::BeginPlay()
{
  Super::BeginPlay();

}

void ADashSwordsman::Tick(float DeltaSeconds)
{

  Super::Tick(DeltaSeconds);
  AttackStart = GetActorLocation();
}

void ADashSwordsman::Attack()
{
  FVector Start;
  FVector End;
  if (bIsFacingRight)
  {
    Start = AttackStart + FVector(30.f, 0.f, 0.f);
    End = Start + FVector::ForwardVector * 100;
  }
  else
  {
    Start = AttackStart + FVector(-30.f, 0.f, 0.f);
    End = Start + FVector::ForwardVector * -100;
  }

  FHitResult HitData(ForceInit);
  GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Attack is working"));
  if (UStaticFunctionLibrary::Trace(GetWorld(), this, Start, End, HitData))
  {
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Attack is working"));
    AGeneralCharacter * EP = Cast<AGeneralCharacter>(HitData.GetActor());
    if (EP)
    {
      GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Attack is working"));
      TSubclassOf < UDamageType > const ValidDamageTypeClass = TSubclassOf<UDamageType>(UDamageType::StaticClass());
      FDamageEvent DamageEvent(ValidDamageTypeClass);

      EP->TakeDamage(DamageAmount, DamageEvent, Controller, this);
    }
  }
}

