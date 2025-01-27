// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance/ShooterCharacterAnimInstance.h"
#include "Character/ShootingGameBaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "KismetAnimationLibrary.h"
#include "AbilitySystem/ShootingGameASC.h"
#include "ShootingGameFunctionLibrary.h"
#include "ShootingGameGameplayTags.h"
#include "Component/Combet/PawnCombetComponentBase.h"


void UShooterCharacterAnimInstance::NativeInitializeAnimation()
{
	OwningCharacter = Cast<AShootingGameBaseCharacter>(TryGetPawnOwner());

	if (OwningCharacter)
	{
		OwningMovementComponent = OwningCharacter->GetCharacterMovement();
	}
}

void UShooterCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!OwningCharacter || !OwningMovementComponent) return;

	GroundSpeed = OwningCharacter->GetVelocity().Size2D();
	bHasAcceleration = OwningMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.f;
	LocomationDirection = UKismetAnimationLibrary::CalculateDirection(OwningCharacter->GetVelocity(), OwningCharacter->GetActorRotation());
	bHasZoomIn = UShootingGameFunctionLibrary::NativeDoseActorHaveTag(OwningCharacter, ShootingGameTags::Player_Status_Zoom);
	if (bHasAcceleration || bHasZoomIn)
	{
		OwningCharacter->bUseControllerRotationYaw = true;
	}
	else
	{
		OwningCharacter->bUseControllerRotationYaw = false;
	}
	Aim = OwningCharacter->GetBaseAimRotation().Pitch;

	FGameplayTag WeaponTag = OwningCharacter->GetPawnCombetComponent()->CurrentEquippedWeaponTag;

	if (WeaponTag == ShootingGameTags::Player_Weapon_SMG11)
	{
		AimOffsetType = EAimOffsetType::SMG11;
	}

	else if (WeaponTag == ShootingGameTags::Player_Weapon_AR4)
	{
		AimOffsetType = EAimOffsetType::AR4;
	}

}