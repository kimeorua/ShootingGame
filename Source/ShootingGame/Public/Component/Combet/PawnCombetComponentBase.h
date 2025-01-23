// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Component/PawnExtensionComponentBase.h"
#include "GameplayTagContainer.h"
#include "PawnCombetComponentBase.generated.h"

class AShootingGameWeaponBase;

/**
 * 
 */
UCLASS()
class SHOOTINGGAME_API UPawnCombetComponentBase : public UPawnExtensionComponentBase
{
	GENERATED_BODY()

public:

	/// <summary>
	/// 무기를 등록합니다.
	/// </summary>
	/// <param name="WeaponTagToRegister">등록할 무기 Tag</param>
	/// <param name="InWeaponToRegister">등록할 무기 BP</param>
	/// <param name="bRegisterAsEquippedWeapon">장착 여부</param>
	UFUNCTION(BlueprintCallable, Category = "Shooter|Combet")
	void RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, AShootingGameWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon = false);

	/// <summary>
	/// 현재 가지고 있는 무기를 Tag를 통해 반환
	/// </summary>
	/// <param name="InWeaponTagToGet">반환 받을 무기의 Tag</param>
	/// <returns>해당 Tag를 가지고 있는 무기</returns>
	UFUNCTION(BlueprintCallable, Category = "Shooter|Combet")
	AShootingGameWeaponBase* GetShooterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const;

	/// <summary>
	/// 현재 장착한 무기를 반환
	/// </summary>
	/// <returns>장착된 무기</returns>
	UFUNCTION(BlueprintCallable, Category = "Shooter|Combet")
	AShootingGameWeaponBase* GetShooterCurrentEquippedWeapon() const;

	UPROPERTY(BlueprintReadWrite, Category = "Shooter|Combet")
	FGameplayTag CurrentEquippedWeaponTag;

private:
	TMap<FGameplayTag, AShootingGameWeaponBase*> ShooterCarriedWeaponMap;
	
};
