// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "ChampionWidgets.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMERBATTLE_API UChampionWidgets : public UUserWidget
{
  GENERATED_BODY()

public:

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Users")
    int index;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Users")
    bool bPlayerOneActive;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Users")
    bool bPlayerTwoActive;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Users")
    bool bPlayerThreeActive;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Users")
    bool bPlayerFourActive;
	

  UFUNCTION(BlueprintCallable, Category = "Users")
    void SetPlayerActive(APlayerController * PlayerController);
};
