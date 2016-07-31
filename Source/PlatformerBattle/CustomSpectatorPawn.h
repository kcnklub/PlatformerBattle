// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/SpectatorPawn.h"
#include "CustomSpectatorPawn.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMERBATTLE_API ACustomSpectatorPawn : public ASpectatorPawn
{
		GENERATED_BODY()


public:

		virtual void BeginPlay() override;
	
};
