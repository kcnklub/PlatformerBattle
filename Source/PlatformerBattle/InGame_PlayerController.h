// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "InGame_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMERBATTLE_API AInGame_PlayerController : public APlayerController
{
  GENERATED_BODY()

  FTimerHandle DeathHandle;

public: 
  
  AInGame_PlayerController();
  
  int Score;

  void OnDeath();

  void Respawn();

  void AdvanceRespawnTimer();

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Respawn)
  int RespawnTime;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Respawn)
  int RespawnTimer;

  virtual void BeginPlay() override;

};
