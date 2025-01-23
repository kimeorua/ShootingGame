// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAsset/StartUpData/DataAsset_ShooterStartUpData.h"
#include "AbilitySystem/Abilities/ShootingGameGameplayAbility.h"
#include "AbilitySystem/ShootingGameASC.h"

void UDataAsset_ShooterStartUpData::GiveToAbilitySystemComponent(UShootingGameASC* InShootingGameASCToGive, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InShootingGameASCToGive, ApplyLevel);

	for (const FShooterAbilitySet& AbilitiySet : HeroStartUpAbilities)
	{
		if (!AbilitiySet.IsVaild()) { continue; }

		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilitiySet.AbilityToGrant);
		AbilitySpec.SourceObject = InShootingGameASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.DynamicAbilityTags.AddTag(AbilitiySet.InputTag);

		InShootingGameASCToGive->GiveAbility(AbilitySpec);
	}
}
