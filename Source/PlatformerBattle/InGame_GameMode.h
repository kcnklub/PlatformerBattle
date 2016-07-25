// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PlatformerBattleGameMode.h"
#include "InGame_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMERBATTLE_API AInGame_GameMode : public APlatformerBattleGameMode
{
  GENERATED_BODY()


public:

    AInGame_GameMode();

    virtual AActor * ChoosePlayerStart_Implementation(AController * Player) override;
	
	
};
