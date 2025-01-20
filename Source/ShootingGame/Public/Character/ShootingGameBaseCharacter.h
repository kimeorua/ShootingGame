// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "ShootingGameBaseCharacter.generated.h"

class UShootingGameASC;
class UDataAsset_StartUpDataBase;
class UShootingGameAttributeSet;

UCLASS()
class SHOOTINGGAME_API AShootingGameBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShootingGameBaseCharacter();

	//~Begin IAbilitySystemInterface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~End IAbilitySystemInterface

	FORCEINLINE UShootingGameASC* GetShootingGameASC() const { return ShootingGameASC; }
	FORCEINLINE UShootingGameAttributeSet* GetAttributeSet() const { return ShootingGameAttributeSet; }

protected:

	//~Begin APawn interface
	virtual void PossessedBy(AController* NewController) override;
	//~End APawn interface

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UShootingGameASC* ShootingGameASC;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UShootingGameAttributeSet* ShootingGameAttributeSet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Character Data")
	TSoftObjectPtr<UDataAsset_StartUpDataBase> StartUpData;
};
