// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "StaticFunctionLibrary.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class Champion : uint8
{
  DashSwordsman,
  Risputa
};

UCLASS()
class PLATFORMERBATTLE_API UStaticFunctionLibrary : public UObject
{
	GENERATED_BODY()
	
public:

  static bool Trace(UWorld* World,
    AActor * ActorToIgnore,
    const FVector& Start,
    const FVector& End,
    FHitResult& HitOut,
    ECollisionChannel CollisionChannel = ECC_Pawn,
    bool ReturnPhsMat = false);


	/*

	//Working on an custom delay that will set up a timer that will act as a delay when this function is called.

	static void CustomDelay(UWorld* World,
		FTimerDelegate FunctionCall,
		const float DelayTime);
	*/
	
};
