// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAsset/StartUpData/DataAsset_StartUpDataBase.h"
#include "AbilitySystem/Abilities/ShootingGameGameplayAbility.h"
#include "AbilitySystem/ShootingGameASC.h"

void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(UShootingGameASC* InShootingGameASCToGive, int32 ApplyLevel)
{
	check(InShootingGameASCToGive);

	GrantAbilities(ActivateOnGivenAbilities, InShootingGameASCToGive, ApplyLevel);
	GrantAbilities(ReactivateAbilities, InShootingGameASCToGive, ApplyLevel);
}

void UDataAsset_StartUpDataBase::GrantAbilities(const TArray<TSubclassOf<UShootingGameGameplayAbility>>& InAbilitiesToGive, UShootingGameASC* InShootingGameASCToGive, int32 ApplyLevel)
{
	if (InAbilitiesToGive.IsEmpty()) { return; }

	for (const TSubclassOf<UShootingGameGameplayAbility>& Ability : InAbilitiesToGive)
	{
		if (!Ability) { continue; }

		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InShootingGameASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;

		InShootingGameASCToGive->GiveAbility(AbilitySpec);
	}
}
