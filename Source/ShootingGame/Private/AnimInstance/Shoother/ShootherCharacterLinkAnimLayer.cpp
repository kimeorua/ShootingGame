// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance/Shoother/ShootherCharacterLinkAnimLayer.h"
#include "AnimInstance/Shoother/ShooterPlayerAnimInstance.h"

UShooterPlayerAnimInstance* UShootherCharacterLinkAnimLayer::GetShooterPlayerAnimInstance() const
{
    return Cast<UShooterPlayerAnimInstance>(GetOwningComponent()->GetAnimInstance());
}
