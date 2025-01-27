// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CombetComponentInterface.generated.h"

class UPawnCombetComponentBase;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCombetComponentInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SHOOTINGGAME_API ICombetComponentInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual UPawnCombetComponentBase* GetPawnCombetComponent() const = 0;
};
