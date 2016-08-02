// Fill out your copyright notice in the Description page of Project Settings.

#include "PlatformerBattle.h"
#include "ChampionWidgets.h"
#include "Menu_PlayerController.h"


void UChampionWidgets::SetPlayerActive(APlayerController * PlayerController)
{
  AMenu_PlayerController * PC = Cast<AMenu_PlayerController>(PlayerController);
  if (PC)
  {
    switch (PC->PlayerIndex)
    {
      case 0:
        if (PC->ChampionSelectionIndex == index)
        {
          bPlayerOneActive = true;
        }
        else
        {
          bPlayerOneActive = false;
        }
      case 1:
        if (PC->ChampionSelectionIndex == index)
        {
          bPlayerTwoActive = true;
        }
        else
        {
          bPlayerTwoActive = false;
        }
      case 2:
        if (PC->ChampionSelectionIndex == index)
        {
          bPlayerThreeActive = true;
        }
        else
        {
          bPlayerThreeActive = false;
        }
      case 3:
        if (PC->ChampionSelectionIndex == index)
        {
          bPlayerFourActive = true;
        }
        else
        {
          bPlayerFourActive = false;
        }
    }
  }
}

