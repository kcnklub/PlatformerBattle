// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GeneralCharacter.h"
#include "RisputaBasicAttack.h"
#include "StaticFunctionLibrary.h"
#include "Risputa.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAttacked, bool, bIsAttacking);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTeleport, bool, bIsTeleporting);

/**
 * 
 */
UCLASS()
class PLATFORMERBATTLE_API ARisputa : public AGeneralCharacter
{
	GENERATED_BODY()
	
protected:

  virtual void SetupPlayerInputComponent(class UInputComponent * InputComponent) override;
	
  virtual void Tick(float DeltaSeconds) override;

  void Attack();

public:

  ARisputa();
  
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AttackClass")
  TSubclassOf<ARisputaBasicAttack> BasicAttack;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttackClass")
    UPaperFlipbookComponent * Reticle;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttackClass")
    UPaperFlipbook * GroundReticle;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttackClass")
    UPaperFlipbook * AirBornReticle;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerVitals)
    float DamageAmount;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerVitals)
    float RangeOfBasic;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerVitals)
    bool CurrAttacking;

  UPROPERTY(BlueprintAssignable, Category = "AttackEvents")
    FAttacked Attacking;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Reticle")
		FVector GroundCheck;
	bool bIsLockedOrientation;
	void UpdateCharacter();
	void LockOrientation();

	//Teleporting variables and functions;
	UPROPERTY(BlueprintAssignable, Category = "Teleport")
	FTeleport Teleporting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Teleport")
	bool bIsTeleporting;
	
	void Teleport();

	float DistanceOfTrace;
};
