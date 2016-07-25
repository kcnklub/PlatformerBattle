// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GeneralCharacter.h"
#include "DashSwordsman.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMERBATTLE_API ADashSwordsman : public AGeneralCharacter
{
  GENERATED_BODY()


  UPaperFlipbookComponent * JumpAnim;


  UPaperFlipbookComponent * AttackAnim;

protected:

  virtual void SetupPlayerInputComponent(class UInputComponent * InputComponent) override;

  virtual void BeginPlay() override;

  virtual void Tick(float DeltaSeconds) override;

  void Attack();

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
    FVector AttackStart;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerVitals)
    float DamageAmount;

  
};
