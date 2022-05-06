// Fill out your copyright notice in the Description page of Project Settings.


#include "DestroyBaseFactory.h"

#include "Particles/ParticleSystemComponent.h"

// Sets default values
ADestroyBaseFactory::ADestroyBaseFactory()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>("DefaultRoot");
	
	BuildingMesh = CreateDefaultSubobject<UStaticMeshComponent>("BuildingMesh");
	BuildingMesh->SetupAttachment(RootComponent);

	CreateEffect = CreateDefaultSubobject<UParticleSystemComponent>("CreateEffect");
	CreateEffect->SetupAttachment(BuildingMesh);
	
}

// Called when the game starts or when spawned
void ADestroyBaseFactory::BeginPlay()
{
	Super::BeginPlay();
	CreateEffect->ActivateSystem();
}

// Called every frame
void ADestroyBaseFactory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}
