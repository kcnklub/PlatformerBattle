// Fill out your copyright notice in the Description page of Project Settings.

#include "PlatformerBattle.h"
#include "GeneralCharacter.h"
#include "PaperFlipbookComponent.h"
#include "InGame_PlayerController.h"
#include "StaticFunctionLibrary.h"
#include "Engine.h"

AGeneralCharacter::AGeneralCharacter()
{
  //Create the Camera and Camera arm;
  Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
  CameraArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraArm"));

  //Attach Camera and Camera Arm to the Root and each other;
  CameraArm->AttachTo(GetRootComponent());
  Camera->AttachTo(CameraArm, USpringArmComponent::SocketName);

  //Constrain the character to a plane. 
  GetCharacterMovement()->bConstrainToPlane = true;
  GetCharacterMovement()->SetPlaneConstraintNormal(FVector(0.0f, -1.0f, 0.0f));

  //Set Network replication to true;
  GetSprite()->SetIsReplicated(true);
  bReplicates = true;

  bCanBeDamaged = true;

  bIsDead = false;
}

void AGeneralCharacter::BeginPlay()
{
  Super::BeginPlay();
  
  //Set health to a default value;
  m_Health = m_MaxHealth;
}

void AGeneralCharacter::Tick(float DeltaSeconds)
{
  Super::Tick(DeltaSeconds);
  
  UpdateCharacter();
}

void AGeneralCharacter::SetupPlayerInputComponent(class UInputComponent * InputCompnent)
{
  //Action Bindings;
  InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);

  //Axis Bindings;
  InputComponent->BindAxis("MoveRight", this, &AGeneralCharacter::MoveRight);
}

float AGeneralCharacter::TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser)
{

  float ActualDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

  m_Health -= static_cast<int>(ActualDamage);
  if (bCanBeDamaged)
  {
    if (m_Health < 0)
    {
      AGeneralCharacter * Character = Cast<AGeneralCharacter>(DamageCauser);
      if (Character)
      {
        AInGame_PlayerController * Enemy = Cast<AInGame_PlayerController>(Character->Controller);
        if (Enemy)
        {
          Enemy->Score++;
        }
      }
      AInGame_PlayerController * Player = Cast<AInGame_PlayerController>(Controller);
      Player->OnDeath();
      Death();
    }
  }

  return ActualDamage;
}

void AGeneralCharacter::MoveRight(float Value)
{
  AddMovementInput(FVector::ForwardVector, Value);
}

void AGeneralCharacter::UpdateCharacter()
{

  const FVector PlayerVelocity = GetVelocity();
  float TravelDirection = PlayerVelocity.X;

  if (Controller != nullptr)
  {
    if (TravelDirection < 0.0f)
    {
      GetSprite()->RelativeRotation = FRotator(0.0, 0.0f, 0.0f);
      bIsFacingRight = false;
    }
    else if (TravelDirection > 0.0f)
    {
      GetSprite()->RelativeRotation = FRotator(0.0, 180.0f, 0.0f);
      bIsFacingRight = true;
    }
  }
}

void AGeneralCharacter::Death()
{
  bIsDead = true;
  GetWorldTimerManager().SetTimer(ClearCharacter, this, &AGeneralCharacter::AdvanceClearCharacter, true, 1.0f);
}

void AGeneralCharacter::AdvanceClearCharacter()
{
  ClearCharacterTimer--;

  if (ClearCharacterTimer < 1)
  {
    Destroy();
    GetWorldTimerManager().ClearTimer(ClearCharacter);
  }
}

