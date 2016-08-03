// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "StaticFunctionLibrary.h"
#include "Risputa.h"
#include "DashSwordsman.h"
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

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gamemode")
    Champion SelectedChampionClass;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gamemode")
    TSubclassOf<ADashSwordsman> DashSwordsmanClass;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gamemode")
    TSubclassOf<ARisputa> RisputaClass;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gamemode")
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
