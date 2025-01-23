// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Component/Combet/PawnCombetComponentBase.h"
#include "ShooterCombetComponent.generated.h"

class AShooterWeapon;

/**
 * 
 */
UCLASS()
class SHOOTINGGAME_API UShooterCombetComponent : public UPawnCombetComponentBase
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Shooter|Combet")
	AShooterWeapon* GetShooterPlayerCarriedWeaponByTag(FGameplayTag InWeaponTag) const; 
};
