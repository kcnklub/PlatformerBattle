// Fill out your copyright notice in the Description page of Project Settings.

#include "PlatformerBattle.h"
#include "Menu_PlayerController.h"


void AMenu_PlayerController::UpdateChampionSelectionIndex()
{
  float XValue, YValue;
  GetInputAnalogStickState(EControllerAnalogStick::CAS_LeftStick, XValue, YValue);
  if (XValue > 0.7f)
  {
    ChampionSelectionIndex++;
  }
  else if(XValue < -0.7f)
  {
    ChampionSelectionIndex--;
  }
}


