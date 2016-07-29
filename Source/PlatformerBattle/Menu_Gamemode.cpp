// Fill out your copyright notice in the Description page of Project Settings.

#include "PlatformerBattle.h"
#include "Menu_Gamemode.h"


void AMenu_Gamemode::BeginPlay()
{
  Super::BeginPlay();
  ChangeMenuWidget(StartingWidgetClass);
}

void AMenu_Gamemode::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
  if (CurrentWidget != nullptr)
  {
    CurrentWidget->RemoveFromViewport();
    CurrentWidget = nullptr;
  }

  if (NewWidgetClass != nullptr)
  {
    CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);
    if (CurrentWidget != nullptr)
    {
      CurrentWidget->AddToViewport();
    }
  }
}
