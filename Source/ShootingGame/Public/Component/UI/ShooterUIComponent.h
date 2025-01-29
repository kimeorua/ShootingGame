// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Component/UI/PawnUIComponent.h"
#include "ShooterUIComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnShowCrossHairDelegate, bool, bShowCrossHair);

/**
 * 
 */
UCLASS()
class SHOOTINGGAME_API UShooterUIComponent : public UPawnUIComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnShowCrossHairDelegate OnShowCrossHairDelegate;
};
