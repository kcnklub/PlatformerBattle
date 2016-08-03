// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PaperFlipbookComponent.h"
#include "GeneralCharacter.h"
#include "RisputaBasicAttack.generated.h"

UCLASS()
class PLATFORMERBATTLE_API ARisputaBasicAttack : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARisputaBasicAttack();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision")
  class UCapsuleComponent * CollisionComponent;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sprite")
  class UPaperFlipbookComponent * Sprite;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
  float AttackDamage;

private:

  bool bIsPlayerAirborn;

  AController * OwningController;

public:

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sprite")
  class UPaperFlipbook * GroundedAnim;
    
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sprite")
  class UPaperFlipbook * InAirAnim;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Checks")
  FVector GroundCheck;

  UFUNCTION()
    void OnOverlapBegin(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	

  FORCEINLINE void setIsPlayerAirborn(bool isAirBorn) { bIsPlayerAirborn = isAirBorn; }
  FORCEINLINE void setAttackDamage(float Damage) { AttackDamage = Damage; }
  FORCEINLINE void setOwningController(AController * Character) { OwningController = Character; }
};
