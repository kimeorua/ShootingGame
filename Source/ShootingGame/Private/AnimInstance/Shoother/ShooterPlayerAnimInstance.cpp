// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance/Shoother/ShooterPlayerAnimInstance.h"
#include "Character/ShooterCharacter.h"

void UShooterPlayerAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	if (OwningCharacter)
	{
		OwningShooterCharacter = Cast<AShooterCharacter>(OwningCharacter);
	}
}

void UShooterPlayerAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
}
