// Fill out your copyright notice in the Description page of Project Settings.

#include "PlatformerBattle.h"
#include "StaticFunctionLibrary.h"
#include "RisputaBasicAttack.h"


// Sets default values
ARisputaBasicAttack::ARisputaBasicAttack()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

  CollisionComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionComponent"));
  Sprite = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Sprite"));

  CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ARisputaBasicAttack::OnOverlapBegin);

  RootComponent = CollisionComponent;
  Sprite->AttachTo(RootComponent);

  bIsPlayerAirborn = false;

  InitialLifeSpan = 0.5f;

}

// Called when the game starts or when spawned
void ARisputaBasicAttack::BeginPlay()
{
	Super::BeginPlay();
	

  //Line tracing down to determine what animation to play
  bIsPlayerAirborn = true;
  FHitResult HitData(ForceInit);
  if (UStaticFunctionLibrary::Trace(GetWorld(), this, GetActorLocation(), GetActorLocation() + GroundCheck, HitData))
  {
    bIsPlayerAirborn = false;
  }
  
}

// Called every frame
void ARisputaBasicAttack::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
  if (bIsPlayerAirborn)
  {
    Sprite->SetFlipbook(InAirAnim);
  }
  else
  {
    Sprite->SetFlipbook(GroundedAnim);
  }

}

void ARisputaBasicAttack::OnOverlapBegin(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
  AGeneralCharacter * Character = Cast<AGeneralCharacter>(OtherActor);
  if (Character)
  {
    TSubclassOf<UDamageType> const ValidDamageTypeClass = TSubclassOf<UDamageType>(UDamageType::StaticClass());
    FDamageEvent DamageEvent(ValidDamageTypeClass);
    Character->TakeDamage(AttackDamage, DamageEvent, OwningController, this);
  }
}

