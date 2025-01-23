// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/Weapon/ShootingGameWeaponBase.h"
#include "ShootingType/ShootingStructType.h"
#include "GameplayAbilitySpecHandle.h"
#include "ShooterWeapon.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTINGGAME_API AShooterWeapon : public AShootingGameWeaponBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WeaponData")
	FShooterCharacterWeaponData ShooterCharacterWeaponData;

	UFUNCTION(BlueprintCallable)
	void AssignGrantedAbilitySpecHandle(const TArray<FGameplayAbilitySpecHandle>& InSpecHandle);

	UFUNCTION(BlueprintPure)
	TArray<FGameplayAbilitySpecHandle> GetGrantedAbilitySpecHandle()const;

private:
	TArray<FGameplayAbilitySpecHandle> GraintedAbilitySpecHandle;

};
