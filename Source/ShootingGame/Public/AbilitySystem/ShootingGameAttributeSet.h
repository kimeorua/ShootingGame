// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystem/ShootingGameASC.h"
#include "ShootingGameAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

class IUIComponentInterface;
/**
 * 
 */
UCLASS()
class SHOOTINGGAME_API UShootingGameAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UShootingGameAttributeSet();
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)override;

	UPROPERTY(BlueprintReadOnly, Category = "Ammo")
	FGameplayAttributeData CurrentAmmo;
	ATTRIBUTE_ACCESSORS(UShootingGameAttributeSet, CurrentAmmo)

	UPROPERTY(BlueprintReadOnly, Category = "Ammo")
	FGameplayAttributeData MaxAmmo;
	ATTRIBUTE_ACCESSORS(UShootingGameAttributeSet, MaxAmmo)

private:
	TWeakInterfacePtr<IUIComponentInterface>CachedPawnUIInterface;

};
