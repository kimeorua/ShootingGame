// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/Weapon/ShootingGameWeaponBase.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AShootingGameWeaponBase::AShootingGameWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;


	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	SetRootComponent(WeaponMesh);
}

