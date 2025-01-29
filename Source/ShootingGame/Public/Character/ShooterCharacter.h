// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/ShootingGameBaseCharacter.h"
#include "GameplayTagContainer.h"
#include "ShooterCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UDataAsset_InputConfig;
struct FInputActionValue;
class UShooterCombetComponent;
class UShooterUIComponent;

/**
 * 
 */
UCLASS()
class SHOOTINGGAME_API AShooterCharacter : public AShootingGameBaseCharacter
{
	GENERATED_BODY()

public:
	AShooterCharacter();

	// ~Begin ICombetComponentInterface
	virtual  UPawnCombetComponentBase* GetPawnCombetComponent() const override;
	// ~End ICombetComponentInterface

	// ~Begin IUIComponentInterface
	virtual UPawnUIComponent* GetPawnUIComponent() const override;
	virtual UShooterUIComponent* GetShooterUIComponent() const;
	// ~End IUIComponentInterface

protected:
	//~Begin APawn interface
	virtual void PossessedBy(AController* NewController) override;
	//~End APawn interface

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)override;
	virtual void BeginPlay() override;

private:
#pragma region Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FllowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combet", meta = (AllowPrivateAccess = "true"))
	UShooterCombetComponent* ShooterCombetComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI", meta = (AllowPrivateAccess = "true"))
	UShooterUIComponent* ShooterUIComponent;
#pragma endregion

#pragma region Inputs
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Character Data", meta = (AllowPrivateAccess = "true"))
	UDataAsset_InputConfig* InputConfigDataAsset;

	void Input_Move(const FInputActionValue& InputActionVale);
	void Input_Look(const FInputActionValue& InputActionVale);

	void Input_AbilityInputPressed(FGameplayTag InInputTag);
	void Input_AbilityInputReleased(FGameplayTag InInputTag);

#pragma endregion


public:
	FORCEINLINE UShooterCombetComponent* GetShooterCombetComponent() const { return ShooterCombetComponent; }
};
