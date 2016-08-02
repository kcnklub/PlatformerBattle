// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GeneralCharacter.h"
#include "Risputa.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMERBATTLE_API ARisputa : public AGeneralCharacter
{
	GENERATED_BODY()
	
protected:

  virtual void SetupPlayerInputComponent(class UInputComponent * InputComponent) override;
	
};
