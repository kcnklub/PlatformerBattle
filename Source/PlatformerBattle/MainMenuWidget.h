// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMERBATTLE_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Indexing)
    int ButtonIndex;
	
};
