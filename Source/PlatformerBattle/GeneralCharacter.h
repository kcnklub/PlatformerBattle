// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PaperCharacter.h"
#include "GeneralCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMERBATTLE_API AGeneralCharacter : public APaperCharacter
{
	GENERATED_BODY()
	
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
  class UCameraComponent * Camera;

  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
  class USpringArmComponent * CameraArm;

  FTimerHandle ClearCharacter;

protected:

  //Animation Values set in blueprints;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
  class UPaperFlipbook * RunningAnim;
  
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
  class UPaperFlipbook * IdleAnim;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
  class UPaperFlipbook * LandingAnim;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
  class UPaperFlipbook * DeathAnim;
	
  //functions for movement and animations
  void MoveRight(float Value);

  void UpdateCharacter();

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
  bool bIsFacingRight;

  //virtual overrides;
  virtual void SetupPlayerInputComponent(class UInputComponent * InputComponent) override;

  virtual void BeginPlay() override;

public:

  AGeneralCharacter();
  //vitals;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerVitals)
    int m_MaxHealth;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerVitals)
    int m_Health;

  virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override;

  virtual void Tick(float DeltaSeconds) override;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerVitals)
  bool bIsDead;

  void Death();
  void AdvanceClearCharacter();

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ClearCharacter)
  int ClearCharacterTimer;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Jump)
  float JumpSpeed;

  void CustomJump();

  //Get Private pointers;
  FORCEINLINE class UCameraComponent * GetCameraComponent() const { return Camera; }
  FORCEINLINE class USpringArmComponent * GetCameraArmComponent() const { return CameraArm; }
	
};
