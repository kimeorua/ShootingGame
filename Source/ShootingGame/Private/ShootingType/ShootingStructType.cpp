// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootingType/ShootingStructType.h"
#include "AbilitySystem/Abilities/ShootingGameGameplayAbility.h"

bool FShooterAbilitySet::IsVaild() const
{
	return InputTag.IsValid() && AbilityToGrant;
}
