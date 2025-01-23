// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataAsset/StartUpData/DataAsset_StartUpDataBase.h"
#include "ShootingType/ShootingStructType.h"
#include "DataAsset_ShooterStartUpData.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTINGGAME_API UDataAsset_ShooterStartUpData : public UDataAsset_StartUpDataBase
{
	GENERATED_BODY()
	
public:
	virtual void GiveToAbilitySystemComponent(UShootingGameASC* InShootingGameASCToGive, int32 ApplyLevel = 1) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData", meta = (TitleProperty = "InputTag"))
	TArray<FShooterAbilitySet> HeroStartUpAbilities;

};
