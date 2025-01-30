// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/Combet/PawnCombetComponentBase.h"
#include "Item/Weapon/ShootingGameWeaponBase.h"

#include "ShootingGameDegubHelper.h"

void UPawnCombetComponentBase::RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, AShootingGameWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon)
{
	checkf(!(ShooterCarriedWeaponMap.Contains(InWeaponTagToRegister)), TEXT("A Named %s has already been add as carried weapon"), *InWeaponTagToRegister.ToString());
    check(InWeaponToRegister);

    ShooterCarriedWeaponMap.Emplace(InWeaponTagToRegister, InWeaponToRegister);

    if (bRegisterAsEquippedWeapon)
    {
		CurrentEquippedWeaponTag = InWeaponTagToRegister;
    }

    const FString WeaponName = FString::Printf(TEXT("A Weapon named : %s has  benn register using the tag %s"), *InWeaponToRegister->GetName(), *InWeaponTagToRegister.ToString());
	Debug::Print(WeaponName);
}

AShootingGameWeaponBase* UPawnCombetComponentBase::GetShooterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const
{
    if (ShooterCarriedWeaponMap.Contains(InWeaponTagToGet))
    {
        if (AShootingGameWeaponBase* const* FoundWeapon = ShooterCarriedWeaponMap.Find(InWeaponTagToGet))
        {
			return *FoundWeapon;
        }
    }

    return nullptr;
}

AShootingGameWeaponBase* UPawnCombetComponentBase::GetShooterCurrentEquippedWeapon() const
{
	if (!CurrentEquippedWeaponTag.IsValid())
	{
		return nullptr;
	}
	return GetShooterCarriedWeaponByTag(CurrentEquippedWeaponTag);
}

void UPawnCombetComponentBase::SaveCurrentAmmo(float CurrentAmmoToSave)
{
    ShooterCarriedWeaponAmmoMap.Add(CurrentEquippedWeaponTag, CurrentAmmoToSave);
}
