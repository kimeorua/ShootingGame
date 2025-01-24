// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance/ShooterCharacterAnimInstance.h"
#include "Character/ShootingGameBaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "KismetAnimationLibrary.h"
#include "AbilitySystem/ShootingGameASC.h"
#include "ShootingGameFunctionLibrary.h"
#include "ShootingGameGameplayTags.h"

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
	bHasZoomIn = UShootingGameFunctionLibrary::NativeDoseActorHaveTag(OwningCharacter, ShootingGameTags::Player_Status_Zoom);
	if (bHasAcceleration || bHasZoomIn)
	{
		OwningCharacter->bUseControllerRotationYaw = true;
	}
	else
	{
		OwningCharacter->bUseControllerRotationYaw = false;
	}
	LocomationDirection = UKismetAnimationLibrary::CalculateDirection(OwningCharacter->GetVelocity(), OwningCharacter->GetActorRotation());
}