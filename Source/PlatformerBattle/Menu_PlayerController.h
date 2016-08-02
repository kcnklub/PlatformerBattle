// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "Menu_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMERBATTLE_API AMenu_PlayerController : public APlayerController
{
  GENERATED_BODY()

public:

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Index")
    int PlayerIndex;
	
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Index")
    int ChampionSelectionIndex;

  void UpdateChampionSelectionIndex();
};
