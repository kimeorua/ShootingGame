// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpDataBase.generated.h"

class UShootingGameGameplayAbility;
class UShootingGameASC;

/**
 * 
 */
UCLASS()
class SHOOTINGGAME_API UDataAsset_StartUpDataBase : public UDataAsset
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UShootingGameASC* InShootingGameASCToGive, int32 ApplyLevel = 1);

protected:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<UShootingGameGameplayAbility>> ActivateOnGivenAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<UShootingGameGameplayAbility>> ReactivateAbilities;

	void GrantAbilities(const TArray< TSubclassOf<UShootingGameGameplayAbility >>& InAbilityToGive, UShootingGameASC* InShootingGameASCToGive, int32 ApplyLevel = 1);

};
