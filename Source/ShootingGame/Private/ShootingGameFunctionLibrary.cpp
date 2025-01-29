// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootingGameFunctionLibrary.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/ShootingGameASC.h"
#include "Kismet/GameplayStatics.h"
#include "Item/Weapon/Projectile/ShootingGameProjectileBase.h"

UShootingGameASC* UShootingGameFunctionLibrary::NativeGetWrroirASCFromActor(AActor* InActor)
{
	check(InActor);
	return CastChecked<UShootingGameASC>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InActor));
}

void UShootingGameFunctionLibrary::AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd)
{
	UShootingGameASC* ASC = NativeGetWrroirASCFromActor(InActor);
	if (!ASC->HasMatchingGameplayTag(TagToAdd))
	{
		ASC->AddLooseGameplayTag(TagToAdd);
	}
}

void UShootingGameFunctionLibrary::RemoveGameplayTagToActorIfFind(AActor* InActor, FGameplayTag TagToRemove)
{
	UShootingGameASC* ASC = NativeGetWrroirASCFromActor(InActor);
	if (ASC->HasMatchingGameplayTag(TagToRemove))
	{
		ASC->RemoveLooseGameplayTag(TagToRemove);
	}
}

bool UShootingGameFunctionLibrary::NativeDoseActorHaveTag(AActor* InActor, FGameplayTag TagToCheck)
{
	UShootingGameASC* ASC = NativeGetWrroirASCFromActor(InActor);
	return ASC->HasMatchingGameplayTag(TagToCheck);
}

void UShootingGameFunctionLibrary::BP_DoseActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, EShootingGameConfirmType& OutConfirmType)
{
	OutConfirmType = NativeDoseActorHaveTag(InActor, TagToCheck) ? EShootingGameConfirmType::Yes : EShootingGameConfirmType::No;
}

AShootingGameProjectileBase* UShootingGameFunctionLibrary::SpawnProjectile(UClass* SpawnClass, FVector SpawnLocation, FRotator SpawnRotation)
{
	UWorld* World = GEngine->GameViewport->GetWorld();
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	if (World)
	{
		AShootingGameProjectileBase* SpawnedProjectile = World->SpawnActor<AShootingGameProjectileBase>(SpawnClass, SpawnLocation, SpawnRotation, SpawnParameters);
		return SpawnedProjectile;
	}

	return nullptr;
}
