// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ShootingGameBaseCharacter.h"
#include "AbilitySystem/ShootingGameASC.h"
#include "AbilitySystem/ShootingGameAttributeSet.h"
#include "Components/SkeletalMeshComponent.h"

#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AShootingGameBaseCharacter::AShootingGameBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;

	ShootingGameASC= CreateDefaultSubobject<UShootingGameASC>(TEXT("AbilitySystemComponent"));
	ShootingGameAttributeSet = CreateDefaultSubobject<UShootingGameAttributeSet>(TEXT("AttributeSet"));

}

UAbilitySystemComponent* AShootingGameBaseCharacter::GetAbilitySystemComponent() const
{
	return GetShootingGameASC();
}

UPawnCombetComponentBase* AShootingGameBaseCharacter::GetPawnCombetComponent() const
{
	return nullptr;
}

void AShootingGameBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	if (ShootingGameASC)
	{
		ShootingGameASC->InitAbilityActorInfo(this, this);
		ensureMsgf(!(StartUpData.IsNull()), TEXT("Forgot to assign startup data %s"), *GetName());
	}
}