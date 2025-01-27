// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ShooterCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputSubsystems.h"
#include "DataAsset/Input/DataAsset_InputConfig.h"
#include "Component/Input/ShootingGmaeInputComponent.h"
#include "ShootingGameGameplayTags.h"
#include "Kismet/KismetMathLibrary.h"
#include "AbilitySystem/ShootingGameASC.h"
#include "AbilitySystem/ShootingGameAttributeSet.h"
#include "DataAsset/StartUpData/DataAsset_StartUpDataBase.h"
#include "Component/Combet/ShooterCombetComponent.h"

#include "ShootingGameDegubHelper.h"

AShooterCharacter::AShooterCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->TargetArmLength = 200.0f;
	SpringArm->SocketOffset = FVector(0.f, 45.f, 75.f);
	SpringArm->bUsePawnControlRotation = true;

	FllowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FllowCamera"));
	FllowCamera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	FllowCamera->bUsePawnControlRotation = false;

	GetCharacterMovement()->bOrientRotationToMovement = false;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 120.f, 0.f);
	GetCharacterMovement()->MaxWalkSpeed = 220.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	ShooterCombetComponent = CreateDefaultSubobject<UShooterCombetComponent>(TEXT("ShooterCombetComponent"));
}

UPawnCombetComponentBase* AShooterCharacter::GetPawnCombetComponent() const
{
	return ShooterCombetComponent;
}

void AShooterCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	if (!StartUpData.IsNull())
	{
		if (UDataAsset_StartUpDataBase* LoadData = StartUpData.LoadSynchronous())
		{
			LoadData->GiveToAbilitySystemComponent(ShootingGameASC);
		}

	}
}

void AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	checkf(InputConfigDataAsset, TEXT("Forgat to assgin a vaild data asset as input config"))

	ULocalPlayer* LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);

	check(Subsystem);

	Subsystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext, 0);

	UShootingGmaeInputComponent* ShootingGmaeInputComponent = CastChecked<UShootingGmaeInputComponent>(PlayerInputComponent);

	ShootingGmaeInputComponent->BindNativeInputAction(InputConfigDataAsset, ShootingGameTags::InputTag_Move, ETriggerEvent::Triggered, this, &ThisClass::Input_Move);
	ShootingGmaeInputComponent->BindNativeInputAction(InputConfigDataAsset, ShootingGameTags::InputTag_Look, ETriggerEvent::Triggered, this, &ThisClass::Input_Look);

	ShootingGmaeInputComponent->BindAbilityInputAction(InputConfigDataAsset, this, &ThisClass::Input_AbilityInputPressed, &ThisClass::Input_AbilityInputReleased);
}

void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AShooterCharacter::Input_Move(const FInputActionValue& InputActionVale)
{
	const FVector2D MovementVector = InputActionVale.Get<FVector2D>();
	const FRotator MovementRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);

	if (MovementVector.Y != 0.f)
	{
		const FVector ForwardDirection = MovementRotation.RotateVector(FVector::ForwardVector);

		AddMovementInput(ForwardDirection, MovementVector.Y);
	}

	if (MovementVector.X != 0.f)
	{
		const FVector RightDirection = MovementRotation.RotateVector(FVector::RightVector);

		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AShooterCharacter::Input_Look(const FInputActionValue& InputActionVale)
{
	const FVector2D LookAxisVector = InputActionVale.Get<FVector2D>();

	if (LookAxisVector.X != 0.f)
	{
		AddControllerYawInput(LookAxisVector.X);
	}

	if (LookAxisVector.Y != 0.f)
	{
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AShooterCharacter::Input_AbilityInputPressed(FGameplayTag InInputTag)
{
	ShootingGameASC->OnAbilityInputPressed(InInputTag);
}

void AShooterCharacter::Input_AbilityInputReleased(FGameplayTag InInputTag)
{
	ShootingGameASC->OnAbilityInputReleased(InInputTag);
}
