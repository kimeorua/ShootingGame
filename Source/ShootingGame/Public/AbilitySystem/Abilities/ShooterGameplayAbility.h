// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/ShootingGameGameplayAbility.h"
#include "ShooterGameplayAbility.generated.h"

class AShooterCharacter;
class AShooterPlayerController;
class UShooterCombetComponent;
class UShooterUIComponent;
/**
 * 
 */
UCLASS()
class SHOOTINGGAME_API UShooterGameplayAbility : public UShootingGameGameplayAbility
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, Category = "Shooter|Ability")
	AShooterCharacter* GetShooterCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Shooter|Ability")
	AShooterPlayerController* GetShooterPlayerControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Shooter|Ability")
	UShooterCombetComponent* GetShooterCombetComponentFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Shooter|Ability")
	UShooterUIComponent* GetShooterUIComponentFromActorInfo();

private:
	TWeakObjectPtr<AShooterCharacter> CahcedShooterCharacter;
	TWeakObjectPtr<AShooterPlayerController> CahcedShooterController;
};
