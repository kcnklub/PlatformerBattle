// Fill out your copyright notice in the Description page of Project Settings.

#include "PlatformerBattle.h"
#include "InGame_GameMode.h"
#include "CustomPlayerStart.h"
#include "EngineUtils.h"


AInGame_GameMode::AInGame_GameMode()
{
  PrimaryActorTick.bCanEverTick = true;
}

AActor * AInGame_GameMode::ChoosePlayerStart_Implementation(AController * Player)
{
  if (Player)
  {
    TArray<ACustomPlayerStart * > Starts;
    for (TActorIterator<ACustomPlayerStart> StartItr(GetWorld()); StartItr; ++StartItr)
    {
      Starts.Add(*StartItr);
    }

    return Starts[FMath::RandRange(0, Starts.Num() - 1)];
  }
  else
  {
    return NULL;
  }
}

