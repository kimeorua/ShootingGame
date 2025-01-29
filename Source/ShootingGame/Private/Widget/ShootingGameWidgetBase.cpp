// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/ShootingGameWidgetBase.h"
#include "Interface/UIComponentInterface.h"

void UShootingGameWidgetBase::NativeOnInitialized()
{
	if (IUIComponentInterface* UIComponentInterface = Cast<IUIComponentInterface>(GetOwningPlayerPawn()))
	{
		if (UShooterUIComponent* ShooterUIComponent = UIComponentInterface->GetShooterUIComponent())
		{
			BP_OnOwningShooterUIComponentInitalized(ShooterUIComponent);
		}
	}
}
