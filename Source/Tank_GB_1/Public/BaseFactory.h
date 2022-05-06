// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyTank_Pawn.h"
#include "HealthComponent.h"
#include "LevelTrigger.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "Engine/TargetPoint.h"
#include "GameFramework/Actor.h"
#include "DestroyBaseFactory.h"
#include "DestroyBaseFactory_.h"
#include "BaseFactory.generated.h"

UCLASS()
class TANK_GB_1_API ABaseFactory : public AActor, public IDamageTarget
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ABaseFactory();

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category="Components");
	UStaticMeshComponent* BuildingMesh;
    
    UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category="Components");
    UBoxComponent* HitCollider;
    
    UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category="Components");
    UHealthComponent* HealthComponent;
    
    UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category="Components");
    UArrowComponent* SpawnPoint;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Factory");
    TArray<ATargetPoint*> Waypoints;
    
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Factory");
    TSubclassOf<AEnemyTank_Pawn> TankClass;
    
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Factory");
    int MaxTanks = 6;
    
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Factory");
    float SpawnInterval = 15;
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Factory");
	ALevelTrigger* LevelTrigger;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UParticleSystemComponent* DeadEffect;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UAudioComponent* AudioDeadEffect;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UParticleSystemComponent* CreateEffect;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UAudioComponent* AudioCreateEffect;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fabric")
	TSubclassOf<ADestroyBaseFactory> DestroyBaseFactoryClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fabric")
	TSubclassOf<ADestroyBaseFactory_> DestroyBaseFactoryMeshClass;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UArrowComponent* DestroyBaseFactorySpawnPoint;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UArrowComponent* DestroyBaseFactoryMeshSpawnPoint;
	
	virtual void TakeDamage(FDamageData Damage) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void OnTankSpawnTick();
	void OnHealthChanged(float CurrentHealth);
	void OnDestroy();
	void SelfDestroy();

	int TankSpawned = 0;
	FTimerHandle TimerHandle;
	FTimerHandle TimerDestroy;

	UPROPERTY()
	class ADestroyBaseFactory* DestroyFabric;
};
