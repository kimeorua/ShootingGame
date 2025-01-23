// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/ShooterGameplayAbility.h"
#include "Character/ShooterCharacter.h"
#include "Controller/ShooterPlayerController.h"

AShooterCharacter* UShooterGameplayAbility::GetShooterCharacterFromActorInfo()
{
    if (!CahcedShooterCharacter.IsValid())
    {
        CahcedShooterCharacter = Cast<AShooterCharacter>(CurrentActorInfo->AvatarActor);
    }
    return CahcedShooterCharacter.IsValid() ? CahcedShooterCharacter.Get() : nullptr;
}

AShooterPlayerController* UShooterGameplayAbility::GetShooterPlayerControllerFromActorInfo()
{
    if (!CahcedShooterController.IsValid())
    {
        CahcedShooterController = Cast<AShooterPlayerController>(CurrentActorInfo->PlayerController);
    }
    return CahcedShooterController.IsValid() ? CahcedShooterController.Get() : nullptr;
}

UShooterCombetComponent* UShooterGameplayAbility::GetShooterCombetComponentFromActorInfo()
{
    return GetShooterCharacterFromActorInfo()->GetShooterCombetComponent();
}
