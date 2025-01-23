// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstance/ShootingGameBaseAnimInstance.h"
#include "ShootherCharacterLinkAnimLayer.generated.h"

class UShooterPlayerAnimInstance;

/**
 * 
 */
UCLASS()
class SHOOTINGGAME_API UShootherCharacterLinkAnimLayer : public UShootingGameBaseAnimInstance
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, meta = (BlueprintThreadSafe))
	UShooterPlayerAnimInstance* GetShooterPlayerAnimInstance() const;
};
