// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/Combet/ShooterCombetComponent.h"
#include "Item/Weapon/ShooterWeapon.h"

AShooterWeapon* UShooterCombetComponent::GetShooterPlayerCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
	return Cast<AShooterWeapon> (GetShooterCarriedWeaponByTag(InWeaponTag)); 
}
