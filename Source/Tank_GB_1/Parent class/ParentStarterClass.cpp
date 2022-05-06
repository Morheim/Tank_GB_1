// Fill out your copyright notice in the Description page of Project Settings.

#include "ParentStarterClass.h"
#include "Tank_Pawn.h"
#include "Kismet/KismetSystemLibrary.h"
#include "HealthComponent.h"
#include "Components/SkeletalMeshComponent.h"


// Sets default values
AParentStarterClass::AParentStarterClass()
{
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>("BoxComponent");
	RootComponent = BoxComponent;

	BodyMesh = CreateDefaultSubobject<USkeletalMeshComponent>("BodyMesh");
	BodyMesh -> SetupAttachment(RootComponent);
	
	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>("TurretMesh");
	TurretMesh -> SetupAttachment(BodyMesh);

	MachineGunMesh=CreateDefaultSubobject<USkeletalMeshComponent>("MachineGunMesh");
	MachineGunMesh->SetupAttachment(TurretMesh);

	CannonPosition = CreateDefaultSubobject<UArrowComponent>("CannonPosition");
	CannonPosition->SetupAttachment(TurretMesh);

	SprayCannonPosition=CreateDefaultSubobject<UArrowComponent>("SprayCannonPosition");
	SprayCannonPosition->SetupAttachment(MachineGunMesh);
	
	HealthComponent = CreateDefaultSubobject<UHealthComponent>("HealthComponent");
	
}

void AParentStarterClass::TakeDamage(FDamageData Damage)
{
	if(HealthComponent)
		HealthComponent->TakeDamage(Damage);
}

void AParentStarterClass::BeginPlay()
{
	Super::BeginPlay();
}

void AParentStarterClass::Destroyed()
{
	Super::Destroyed();
}

void AParentStarterClass::OnDestroy()
{
	
}

void AParentStarterClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AParentStarterClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
