// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ShootingGameWidgetBase.generated.h"

class UShooterUIComponent;

/**
 * 
 */
UCLASS()
class SHOOTINGGAME_API UShootingGameWidgetBase : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeOnInitialized() override;

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "On Owning Shooter UIComponent Initalized"))
	void BP_OnOwningShooterUIComponentInitalized(UShooterUIComponent* OwingShooterUIComponent);
};