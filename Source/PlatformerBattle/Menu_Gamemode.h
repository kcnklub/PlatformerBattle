// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PlatformerBattleGameMode.h"
#include "Blueprint/UserWidget.h"
#include "Menu_Gamemode.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMERBATTLE_API AMenu_Gamemode : public APlatformerBattleGameMode
{
  GENERATED_BODY()


public:
  virtual void BeginPlay() override;
	
  UFUNCTION(BlueprintCallable, Category = "UMG")
    void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);

protected:
  
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UMG")
    TSubclassOf<UUserWidget> StartingWidgetClass;

  UPROPERTY()
    UUserWidget * CurrentWidget;
	
};
