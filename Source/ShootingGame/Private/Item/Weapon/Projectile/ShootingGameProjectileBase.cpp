// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/Weapon/Projectile/ShootingGameProjectileBase.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AShootingGameProjectileBase::AShootingGameProjectileBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>("ProjectileMesh");
	ProjectileMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	SetRootComponent(ProjectileMesh);

	ProjectileCollision = CreateDefaultSubobject<UCapsuleComponent>("ProjectileCollision");
	ProjectileCollision->SetupAttachment(GetRootComponent());
	ProjectileCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	ProjectileCollision->InitCapsuleSize(2.f, 4.f);

	ProjectileMovementComp = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovementComp");
	ProjectileMovementComp->InitialSpeed = 700.0f; 
	ProjectileMovementComp->MaxSpeed = 900.0f; 
	ProjectileMovementComp->Velocity = FVector(0.0f, 0.0f, 0.0f); 
	ProjectileMovementComp->ProjectileGravityScale = 0.01f;

	SetLifeSpan(3.0f);
}

// Called when the game starts or when spawned
void AShootingGameProjectileBase::BeginPlay()
{
	Super::BeginPlay();
	
}

