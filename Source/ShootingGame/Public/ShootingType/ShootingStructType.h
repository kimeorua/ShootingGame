// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameplayTagContainer.h"
#include "ShootingStructType.generated.h" 


class UShootherCharacterLinkAnimLayer;
class UShootingGameGameplayAbility;
class UInputMappingContext;

USTRUCT(BlueprintType)
struct FShooterAbilitySet
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UShootingGameGameplayAbility> AbilityToGrant;

	bool IsVaild()const;

};

USTRUCT(BlueprintType)
struct FShooterCharacterWeaponData
{
	GENERATED_BODY()

	 UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	 TSubclassOf<UShootherCharacterLinkAnimLayer> WeaponAnimLayerToLink;

	 UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	 UInputMappingContext* WeaponInputMappingContext;

	 UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty = "InputTag"))
	 TArray<FShooterAbilitySet> DefaultWeaponAbilities;

	 UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	 FName WeaponUnequipSocketName;

}; 