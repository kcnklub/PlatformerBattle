// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GeneralCharacter.h"
#include "DashSwordsman.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFirstAttack, bool, HasAttackedOnce);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSecondAttack, bool, HasAttackedTwice);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FThirdAttack, bool, HasAttackedThreeTimes);

/**
 * 
 */
UCLASS()
class PLATFORMERBATTLE_API ADashSwordsman : public AGeneralCharacter
{
  GENERATED_BODY()


  UPaperFlipbookComponent * JumpAnim;

  UPaperFlipbookComponent * AttackAnim;

public:

  UPROPERTY(BlueprintAssignable, Category = "AttackEvents")
    FFirstAttack FirstAttack;

  UPROPERTY(BlueprintAssignable, Category = "AttackEvents")
    FSecondAttack SecondAttack;

  UPROPERTY(BlueprintAssignable, Category = "AttackEvents")
    FThirdAttack ThirdAttack;

protected:

  virtual void SetupPlayerInputComponent(class UInputComponent * InputComponent) override;

  virtual void BeginPlay() override;

  virtual void Tick(float DeltaSeconds) override;

  void Attack();

  void ExecuteAttack(const FVector &StartingPos, const FVector &EndPos);

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attacking")
    bool HasAttackOnce;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attacking")
    bool HasAttackTwice;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attacking")
    bool HasAttackThreeTimes;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
    FVector AttackStart;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerVitals)
    float DamageAmount;

  
};
