// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "PlatformerBattle.h"
#include "PlatformerBattleGameMode.h"
#include "PlatformerBattleCharacter.h"
#include "GeneralCharacter.h"

APlatformerBattleGameMode::APlatformerBattleGameMode()
{
	// set default pawn class to our character
	DefaultPawnClass = AGeneralCharacter::StaticClass();	
}
