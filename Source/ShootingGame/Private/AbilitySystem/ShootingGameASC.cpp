// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/ShootingGameASC.h"
#include "AbilitySystem/Abilities/ShootingGameGameplayAbility.h"
#include "ShootingGameGameplayTags.h"

void UShootingGameASC::OnAbilityInputPressed(const FGameplayTag& InInputTag)
{
	if (!InInputTag.IsValid()) { return; }

	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (!AbilitySpec.DynamicAbilityTags.HasTagExact(InInputTag)) { continue; }

		TryActivateAbility(AbilitySpec.Handle);
	}
}

void UShootingGameASC::OnAbilityInputReleased(const FGameplayTag& InInputTag)
{
	if (!InInputTag.IsValid() || !InInputTag.MatchesTag(ShootingGameTags::InputTag_HoldAction))
	{
		return;
	}

	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (AbilitySpec.DynamicAbilityTags.HasTagExact(InInputTag) && AbilitySpec.IsActive())
		{
			CancelAbilityHandle(AbilitySpec.Handle);
		}
	}
}

void UShootingGameASC::GraintShooterWeaponAbilities(const TArray<FShooterAbilitySet>& InDefalutWeaponAbility, int32 ApplyLevel, TArray <FGameplayAbilitySpecHandle >& OutGraintedAbilitySpecHandle)
{
	if (InDefalutWeaponAbility.IsEmpty())
	{
		return;
	}
	for (const FShooterAbilitySet& AbilitySet : InDefalutWeaponAbility)
	{
		if (!AbilitySet.IsVaild()) { continue; }

		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);

		OutGraintedAbilitySpecHandle.AddUnique(GiveAbility(AbilitySpec));
	}
}

void UShootingGameASC::RemoveShooterWeaponAbilities(UPARAM(ref) TArray<FGameplayAbilitySpecHandle>& InSpecHandleToRemove)
{
	if (InSpecHandleToRemove.IsEmpty()) { return; }

	for (const FGameplayAbilitySpecHandle& SpecHandle : InSpecHandleToRemove)
	{
		if (SpecHandle.IsValid())
		{
			ClearAbility(SpecHandle);
		} 
	}

	InSpecHandleToRemove.Empty();
}
