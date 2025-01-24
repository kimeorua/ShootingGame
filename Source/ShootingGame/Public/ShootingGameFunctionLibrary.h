// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ShootingType/ShootingGameEnumType.h"
#include "ShootingGameFunctionLibrary.generated.h"

class UShootingGameASC;

/**
 * 
 */
UCLASS()
class SHOOTINGGAME_API UShootingGameFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static UShootingGameASC* NativeGetWrroirASCFromActor(AActor* InActor);

	UFUNCTION(BlueprintCallable, Category = "Warrior | Function Library")
	static void AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd);

	UFUNCTION(BlueprintCallable, Category = "Warrior | Function Library")
	static void RemoveGameplayTagToActorIfFind(AActor* InActor, FGameplayTag TagToRemove);

	static bool NativeDoseActorHaveTag(AActor* InActor, FGameplayTag TagToCheck);

	UFUNCTION(BlueprintCallable, Category = "Warrior | Function Library", meta = (DisplayName = "Dose Actor Have Tag", ExpandEnumAsExecs = "OutConfirmType"))
	static void BP_DoseActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, EShootingGameConfirmType& OutConfirmType);
};
