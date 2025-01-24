// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstance/ShootingGameBaseAnimInstance.h"
#include "ShooterCharacterAnimInstance.generated.h"

class AShootingGameBaseCharacter;
class UCharacterMovementComponent;
/**
 * 
 */
UCLASS()
class SHOOTINGGAME_API UShooterCharacterAnimInstance : public UShootingGameBaseAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;

	/// <summary>
	/// 애니메이션 쓰레드에서 동작
	/// </summary>
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

	UPROPERTY()
	AShootingGameBaseCharacter* OwningCharacter;

	UPROPERTY()
	UCharacterMovementComponent* OwningMovementComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomationData")
	float GroundSpeed;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomationData")
	bool bHasAcceleration;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomationData")
	float LocomationDirection;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomationData")
	float bHasZoomIn;
};
