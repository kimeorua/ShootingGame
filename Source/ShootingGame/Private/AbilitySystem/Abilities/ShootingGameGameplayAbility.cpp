// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/ShootingGameGameplayAbility.h"
#include "Component/Combet/PawnCombetComponentBase.h"
#include "AbilitySystem/ShootingGameASC.h"

void UShootingGameGameplayAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);

	if (AbilityActivationPolicy == EAbilityActivationPolicy::OnGiven)
	{
		if (ActorInfo && !Spec.IsActive())
		{
			ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle);
		}
	}
}

void UShootingGameGameplayAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
	
	if (AbilityActivationPolicy == EAbilityActivationPolicy::OnGiven)
	{
		if (ActorInfo)
		{
			ActorInfo->AbilitySystemComponent->ClearAbility(Handle);
		}
	}

}

UPawnCombetComponentBase* UShootingGameGameplayAbility::GetPawnCombetComponentFromActorInfo() const
{
	return GetAvatarActorFromActorInfo()->FindComponentByClass<UPawnCombetComponentBase>();
}

UShootingGameASC* UShootingGameGameplayAbility::GetShooterAbilitySystemComponentFromActorInfo() const
{
	return Cast<UShootingGameASC>(CurrentActorInfo->AbilitySystemComponent);
}
