// Fill out your copyright notice in the Description page of Project Settings.

#include "DestructibleComponentProps.h"

#include "Engine.h"

// Sets default values
ADestructibleComponentProps::ADestructibleComponentProps()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>("Scene Component");
	
	DestructibleComponent = CreateDefaultSubobject<UDestructibleComponent>("Destructible Component");
	DestructibleComponent->SetupAttachment(RootComponent);
	DestructibleComponent->SetNotifyRigidBodyCollision(true);
	
	TriggerComponent = CreateDefaultSubobject<UBoxComponent>("Trigger Component");
	TriggerComponent->SetupAttachment(DestructibleComponent);
	
	IsDestroyed = false;
	IsTriggerEnabled = false;
	
	MaxHealth = 10.f;
	
	DefaultDamage = 1.f;
	DefaultImpulse = 1.f;
	
}

// Called when the game starts or when spawned
void ADestructibleComponentProps::BeginPlay()
{
	Super::BeginPlay();

	DestructibleComponent->OnComponentHit.AddDynamic(this, &ADestructibleComponentProps::Damage);
	
	TriggerComponent->OnComponentBeginOverlap.AddDynamic(this, &ADestructibleComponentProps::Trigger);
	
	CurrentHealth = MaxHealth;
	
}

// Called every frame
void ADestructibleComponentProps::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void ADestructibleComponentProps::Damage(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (!IsDestroyed &&OtherComp->ComponentHasTag("Weapon"))
	{
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Orange, __FUNCTION__);
		CurrentHealth = CurrentHealth - 1.f;
		if (CurrentHealth <= 0.f)
		{
			Destroy(DefaultDamage, Hit.Location, NormalImpulse, DefaultImpulse);
		}
	}
}

void ADestructibleComponentProps::Trigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!IsDestroyed && IsTriggerEnabled && OtherActor->ActorHasTag("Player"))
	{
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Orange, __FUNCTION__);
		Destroy(DefaultDamage, DestructibleComponent->GetComponentLocation(), DestructibleComponent->GetForwardVector(),DefaultImpulse);
	}
}

void ADestructibleComponentProps::Destroy(float Damage, FVector HitLocation, FVector ImpulseDir, float Impulse)
{
	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Orange, __FUNCTION__);

	if (!IsDestroyed)
	{
		IsDestroyed = true;
		DestructibleComponent->ApplyDamage(Damage, HitLocation, ImpulseDir, Impulse);
	}
}
