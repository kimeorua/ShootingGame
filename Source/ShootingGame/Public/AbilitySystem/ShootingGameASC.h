// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "ShootingType/ShootingStructType.h"
#include "ShootingGameASC.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTINGGAME_API UShootingGameASC : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:
	void OnAbilityInputPressed(const FGameplayTag& InInputTag);
	void OnAbilityInputReleased(const FGameplayTag& InInputTag);

	UFUNCTION(BlueprintCallable, Category = "Shooter|Ability", meta = (ApplyLevel = "1"))
	void GraintShooterWeaponAbilities(const TArray<FShooterAbilitySet>& InDefalutWeaponAbility, int32 ApplyLevel, TArray <FGameplayAbilitySpecHandle >& OutGraintedAbilitySpecHandle);

	UFUNCTION(BlueprintCallable, Category = "Shooter|Ability")
	void RemoveShooterWeaponAbilities(UPARAM(ref) TArray<FGameplayAbilitySpecHandle>& InSpecHandleToRemove);
};
