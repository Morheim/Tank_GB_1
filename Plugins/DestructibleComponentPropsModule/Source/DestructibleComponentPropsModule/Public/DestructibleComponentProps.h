// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "DestructibleComponent.h"
#include "Components/BoxComponent.h"

#include "DestructibleComponentProps.generated.h"

UCLASS()
class DESTRUCTIBLECOMPONENTPROPSMODULE_API ADestructibleComponentProps : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADestructibleComponentProps();

	UFUNCTION()
	void Damage(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	UFUNCTION()
	void Trigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	UFUNCTION()
	void Destroy(float Damage, FVector HitLocation, FVector ImpulseDir, float Impulse);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Destractible)
	UBoxComponent* TriggerComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Destractible)
	UDestructibleComponent* DestructibleComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Destractible)
	bool IsTriggerEnabled;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Destractible)
	bool IsDestroyed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Destractible)
	float MaxHealth;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Destractible)
	float CurrentHealth;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Destractible)
	float DefaultDamage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Destractible)
	float DefaultImpulse;

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};