// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ShootingGameBaseCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AShootingGameBaseCharacter::AShootingGameBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;
}
void AShootingGameBaseCharacter::TurnInPlaceEnd()
{
	bTurnLeft = false;
	bTurnRight = false;


	GetCharacterMovement()->bUseControllerDesiredRotation = false;
	GetCharacterMovement()->bOrientRotationToMovement = false;
}
