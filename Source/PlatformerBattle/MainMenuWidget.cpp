// Fill out your copyright notice in the Description page of Project Settings.

#include "PlatformerBattle.h"
#include "MainMenuWidget.h"


void UMainMenuWidget::SwitchToNextMenu(const TSubclassOf<UUserWidget> NewMenu)
{
		AMenu_Gamemode * Gamemode = Cast<AMenu_Gamemode>(GetWorld()->GetAuthGameMode());
		if (Gamemode)
		{
				Gamemode->ChangeMenuWidget(NewMenu);
		}
}

