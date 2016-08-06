// Fill out your copyright notice in the Description page of Project Settings.

#include "PlatformerBattle.h"
#include "StaticFunctionLibrary.h"


bool UStaticFunctionLibrary::Trace(UWorld* World,
                                  AActor * ActorToIgnore,
                                  const FVector& Start,
                                  const FVector& End,
                                  FHitResult& HitOut,
                                  ECollisionChannel CollisionChannel,
                                  bool ReturnPhsMat)
{
  if (!World)
  {
    return false;
  }

  FCollisionQueryParams TraceParams(FName(TEXT("Core Trace")), true, ActorToIgnore);
  TraceParams.bTraceComplex = true;
  //TraceParams.bTraceAsyncScene = true;
  TraceParams.bReturnPhysicalMaterial = ReturnPhsMat;

  //Ignore Actors
  TraceParams.AddIgnoredActor(ActorToIgnore);

  //Re-Initialize hit info
  HitOut = FHitResult(ForceInit);
  
  //Trace
  World->LineTraceSingleByChannel(HitOut, Start, End, CollisionChannel, TraceParams);

  return (HitOut.GetActor() != NULL);
}



/*

//Working on an custom delay that will set up a timer that will act as a delay when this function is called. 

void UStaticFunctionLibrary::CustomDelay(UWorld* World,
	FTimerDelegate FunctionCall,
	const float DelayTime)
{
	FTimerHandle DelayHandle;
	World->GetTimerManager().SetTimer(DelayHandle, FunctionCall, false, DelayTime);
}
*/

