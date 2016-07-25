// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "StaticFunctionLibrary.generated.h"

/**
 * 
 */
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
	
	
};
