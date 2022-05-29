// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseFactory.h"

#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"


// Sets default values
ABaseFactory::ABaseFactory()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>("RootComponent");
	
	BuildingMesh = CreateDefaultSubobject<UStaticMeshComponent>("BuildingMesh");
	BuildingMesh->SetupAttachment(RootComponent);

	HitCollider = CreateDefaultSubobject<UBoxComponent>("HitCollider");
	HitCollider->SetupAttachment(RootComponent);

	SpawnPoint = CreateDefaultSubobject<UArrowComponent>("SpawnPoint");
	SpawnPoint->SetupAttachment(RootComponent);
	
	DeadEffect = CreateDefaultSubobject<UParticleSystemComponent>("DeadEffect");
	DeadEffect->SetupAttachment(BuildingMesh);
	
	AudioDeadEffect = CreateDefaultSubobject<UAudioComponent>("AudioEffect");
	AudioDeadEffect->SetupAttachment(BuildingMesh);

	CreateEffect = CreateDefaultSubobject<UParticleSystemComponent>("CreateEffect");
	CreateEffect->SetupAttachment(BuildingMesh);
	
	AudioCreateEffect = CreateDefaultSubobject<UAudioComponent>("AudioCreateEffect");
	AudioCreateEffect->SetupAttachment(BuildingMesh);

	DestroyBaseFactorySpawnPoint = CreateDefaultSubobject<UArrowComponent>("DestroyBaseFactorySpawnPoint");
	DestroyBaseFactorySpawnPoint->SetupAttachment(RootComponent);
	
	DestroyBaseFactoryMeshSpawnPoint = CreateDefaultSubobject<UArrowComponent>("DestroyBaseFactoryMeshSpawnPoint");
	DestroyBaseFactoryMeshSpawnPoint->SetupAttachment(DestroyBaseFactorySpawnPoint);

	
	HealthComponent = CreateDefaultSubobject<UHealthComponent>("HealthComponent");
	HealthComponent->OnHealthChanged.AddUObject(this, &ABaseFactory::OnHealthChanged);
	HealthComponent->OnDestroy.AddUObject(this, &ABaseFactory::OnDestroy);
}

void ABaseFactory::TakeDamage(FDamageData Damage)
{
	if(HealthComponent)
	   HealthComponent->TakeDamage(Damage);
}

// Called when the game starts or when spawned
void ABaseFactory::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ABaseFactory::OnTankSpawnTick, SpawnInterval, true);
	
}

// Called every frame
void ABaseFactory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseFactory::OnTankSpawnTick()
{
	if(CreateEffect && AudioCreateEffect)
	{
		CreateEffect->ActivateSystem();
		AudioCreateEffect->Play();
		if(TankSpawned > MaxTanks )
			return;
		auto Tank = GetWorld()->SpawnActorDeferred<AEnemyTank_Pawn>(TankClass,SpawnPoint->GetComponentTransform());
		Tank->Waypoints = Waypoints;
		TankSpawned++;
		Tank->Number = TankSpawned;
		UGameplayStatics::FinishSpawningActor(Tank,SpawnPoint->GetComponentTransform());
	}
}

void ABaseFactory::OnHealthChanged(float CurrentHealth)
{
	GEngine->AddOnScreenDebugMessage(23348201, 3, FColor::Orange,FString::Printf(TEXT("Health [Tank Factory]: %f"), CurrentHealth));
}

void ABaseFactory::OnDestroy()
{
	auto Temp = GetActorLocation();
	DeadEffect->ActivateSystem();
	AudioDeadEffect->Play();GetWorld()->SpawnActor<ADestroyBaseFactory>(DestroyBaseFactoryClass,DestroyBaseFactorySpawnPoint->GetComponentLocation(),DestroyBaseFactorySpawnPoint->GetComponentRotation());
	SetActorLocation({-3000, -3000, -3000});
	DeadEffect->SetWorldLocation(Temp);
	AudioDeadEffect->SetWorldLocation(Temp);
	GetWorld()->GetTimerManager().SetTimer(TimerDestroy,this,&ABaseFactory::SelfDestroy,3,false);
	GEngine->AddOnScreenDebugMessage(8823421, 3, FColor::White,FString::Printf(TEXT("Enemy Tank Factory [Destroyed]")));
	GetWorldTimerManager().ClearTimer(TimerHandle);
	if (LevelTrigger)
	{
		LevelTrigger->SetActive(true);
	}
}

void ABaseFactory::SelfDestroy()
{
		Destroy();
}