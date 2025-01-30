// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/ShootingGameAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "Interface/UIComponentInterface.h"
#include "Component/UI/PawnUIComponent.h"
#include "Component/UI/ShooterUIComponent.h"
#include "ShootingGameFunctionLibrary.h"
#include "ShootingGameGameplayTags.h"

UShootingGameAttributeSet::UShootingGameAttributeSet()
{
	InitCurrentAmmo(0.0f);
	InitMaxAmmo(1.0f);
}

void UShootingGameAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	if (!CachedPawnUIInterface.IsValid())
	{
		CachedPawnUIInterface = TWeakInterfacePtr<IUIComponentInterface>(Data.Target.GetAvatarActor());
	}

	checkf(CachedPawnUIInterface.IsValid(), TEXT("%s didn't implement IPawnUIInterface"), *Data.Target.GetAvatarActor()->GetActorLabel());

	if (Data.EvaluatedData.Attribute == GetCurrentAmmoAttribute())
	{
		const float NewCurrentAmmo = FMath::Clamp(GetCurrentAmmo(), 0.0f, GetMaxAmmo());

		SetCurrentAmmo(NewCurrentAmmo);

		if (GetCurrentAmmo() == 0.f)
		{
			UShootingGameFunctionLibrary::AddGameplayTagToActorIfNone(Data.Target.GetAvatarActor(), ShootingGameTags::Shared_Status_AmmoEmpty);
		}

		else if (GetCurrentAmmo() > 0.f)
		{
			UShootingGameFunctionLibrary::RemoveGameplayTagToActorIfFind(Data.Target.GetAvatarActor(), ShootingGameTags::Shared_Status_AmmoEmpty);
		}

		UShooterUIComponent* ShooterUIComponent = CachedPawnUIInterface->GetShooterUIComponent();

		ShooterUIComponent->OnChangedCurrentAmmo.Broadcast(NewCurrentAmmo);
	}

	if (Data.EvaluatedData.Attribute == GetMaxAmmoAttribute())
	{
		UShooterUIComponent* ShooterUIComponent = CachedPawnUIInterface->GetShooterUIComponent();

		ShooterUIComponent->OnChangedMaxAmmo.Broadcast(GetMaxAmmo());
	}
}
