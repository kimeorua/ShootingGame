// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAsset/Input/DataAsset_InputConfig.h"

UInputAction* UDataAsset_InputConfig::FindNativeInputActionbyTag(const FGameplayTag& InInputTag) const
{
	for (const FShootingGameInputConfig& InputActionConfig : NativeInputActions)
	{
		if (InputActionConfig.InputTag == InInputTag && InputActionConfig.InputAction)
		{
			return InputActionConfig.InputAction;
		}
	}

	return nullptr;
}
