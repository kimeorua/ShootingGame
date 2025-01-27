// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAsset/Input/DataAsset_InputConfig.h"
#include "ShootingGmaeInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTINGGAME_API UShootingGmaeInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	/// <summary>
	/// Input Tag를 활용하여 InputAction을 찾고, 해당 InputAction에 함수를 바인딩 함.
	/// </summary>
	template<class UserObject, typename CallbackFunc>
	void BindNativeInputAction
	(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func);

	template<class UserObject, typename CallbackFunc>
	void BindAbilityInputAction(const UDataAsset_InputConfig* InInputConfig, UserObject* ContextObject, CallbackFunc InputPressedFunc, CallbackFunc InputRelasedFunc);
};

template<class UserObject, typename CallbackFunc>
inline void UShootingGmaeInputComponent::BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func)
{
	// InInputConfig가 유효한지 확인
	checkf(InInputConfig, TEXT("Input Config Data Asset is null, Can Not Proceed with Binding"));

	// UInputAction* FoundAction에 InInputConfig에서 InInputTag를 찾음
	if (UInputAction* FoundAction = InInputConfig->FindNativeInputActionbyTag(InInputTag))
	{
		BindAction(FoundAction, TriggerEvent, ContextObject, Func);
	}
}

template<class UserObject, typename CallbackFunc>
inline void UShootingGmaeInputComponent::BindAbilityInputAction(const UDataAsset_InputConfig* InInputConfig, UserObject* ContextObject, CallbackFunc InputPressedFunc, CallbackFunc InputRelasedFunc)
{
	checkf(InInputConfig, TEXT("Input Config Data Asset is null, Can Not Proceed with Binding"));
	for (const FShootingGameInputConfig& AbilityInputActionConfig : InInputConfig->AbilityInputActions)
	{
		if (!AbilityInputActionConfig.IsVaild()) { continue; }

		BindAction(AbilityInputActionConfig.InputAction, ETriggerEvent::Started, ContextObject, InputPressedFunc, AbilityInputActionConfig.InputTag);
		BindAction(AbilityInputActionConfig.InputAction, ETriggerEvent::Completed, ContextObject, InputRelasedFunc, AbilityInputActionConfig.InputTag);
	}
}