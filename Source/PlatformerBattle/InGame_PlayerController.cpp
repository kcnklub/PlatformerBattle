// Fill out your copyright notice in the Description page of Project Settings.

#include "PlatformerBattle.h"
#include "InGame_PlayerController.h"

AInGame_PlayerController::AInGame_PlayerController()
{

}

void AInGame_PlayerController::BeginPlay()
{
  Score = 0;
}

void AInGame_PlayerController::OnDeath()
{
  GetPawn()->bCanBeDamaged = false;
  UnPossess();
  GetWorldTimerManager().SetTimer(DeathHandle, this, &AInGame_PlayerController::AdvanceRespawnTimer, true, 1.0f); 
}

void AInGame_PlayerController::AdvanceRespawnTimer()
{
  RespawnTimer--;

  if (RespawnTimer < 1)
  {
    Respawn();
    RespawnTimer = RespawnTime;
    GetWorldTimerManager().ClearTimer(DeathHandle);
  }
}

void AInGame_PlayerController::Respawn()
{

  AGameMode * Gamemode = GetWorld()->GetAuthGameMode();

  if (Gamemode)
  {
    APawn * NewPawn = Gamemode->SpawnDefaultPawnFor(this, Gamemode->ChoosePlayerStart_Implementation(this));
    Possess(NewPawn);
  }

}


