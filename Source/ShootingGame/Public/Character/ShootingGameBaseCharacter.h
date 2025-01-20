// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShootingGameBaseCharacter.generated.h"

UCLASS()
class SHOOTINGGAME_API AShootingGameBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShootingGameBaseCharacter();

	FORCEINLINE bool GetTurnLeft() const { return bTurnLeft; }
	FORCEINLINE bool GetTurnRight() const { return bTurnRight; }

	UFUNCTION(BlueprintCallable)
	void TurnInPlaceEnd();

protected:
	bool bTurnLeft = false;
	bool bTurnRight = false;
};
