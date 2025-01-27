// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstance/ShooterCharacterAnimInstance.h"
#include "ShooterPlayerAnimInstance.generated.h"

class AShooterCharacter;

/**
 * 
 */
UCLASS()
class SHOOTINGGAME_API UShooterPlayerAnimInstance : public UShooterCharacterAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeInitializeAnimation() override;

	/// <summary>
	/// 애니메이션 쓰레드에서 동작
	/// </summary>
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|Refrence")
	AShooterCharacter* OwningShooterCharacter;
};
