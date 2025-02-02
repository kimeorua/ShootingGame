// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "ShootingGameGameplayAbility.generated.h"

class UPawnCombetComponentBase;
class UShootingGameASC;
class UPawnUIComponent;

UENUM(BlueprintType)
enum class EAbilityActivationPolicy : uint8
{
	OnTriggered,
	OnGiven
};

/**
 * 
 */
UCLASS()
class SHOOTINGGAME_API UShootingGameGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
protected:
	//~ Begin UGameplayAbility Interface
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
	//~ End UGameplayAbility Interface

	UPROPERTY(EditDefaultsOnly, Category = "ShootingGame Ability")
	EAbilityActivationPolicy AbilityActivationPolicy = EAbilityActivationPolicy::OnTriggered;

	UFUNCTION(BlueprintPure, Category = "Shooter|Ability")
	UPawnCombetComponentBase* GetPawnCombetComponentFromActorInfo() const;

	UFUNCTION(BlueprintPure, Category = "Shooter|Ability")
	UPawnUIComponent* GetPawnUIComponentFromActorInfo() const;

	UFUNCTION(BlueprintPure, Category = "Shooter|Ability")
	UShootingGameASC* GetShooterAbilitySystemComponentFromActorInfo() const;
};
