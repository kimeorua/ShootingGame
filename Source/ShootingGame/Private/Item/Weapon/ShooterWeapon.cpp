// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/Weapon/ShooterWeapon.h"

void AShooterWeapon::AssignGrantedAbilitySpecHandle(const TArray<FGameplayAbilitySpecHandle>& InSpecHandle)
{
	GraintedAbilitySpecHandle = InSpecHandle;
}

TArray<FGameplayAbilitySpecHandle> AShooterWeapon::GetGrantedAbilitySpecHandle() const
{
	return GraintedAbilitySpecHandle; 
}
