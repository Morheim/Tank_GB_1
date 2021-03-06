// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Cannon.h"
#include "DamageTarget.h"
#include "HealthComponent.h"
#include "TurretCannon.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Actor.h"
#include "Tank_GB_1/Parent class/ParentStarterClass.h"
#include "Turret.generated.h"

UCLASS()
class TANK_GB_1_API ATurret : public AParentStarterClass
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ATurret();


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Components")
	USphereComponent* RangeSphere;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Fire params")
	TSubclassOf<ATurretCannon> CannonClass;

	UPROPERTY()
	ATurretCannon* TurretCannon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Fire params")
	float TargetingSpeed = 0.01f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Fire params")
	float TargetingRate = 0.005f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Fire params")
	float AimSlack = 6;
	
	virtual void TakeDamage(FDamageData Damage) override;
	

	int AmmoTurret = 1000;
	//void Shoot(int &AmmoTurret);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Destroyed() override;

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* PrimitiveComponent, AActor* Actor, UPrimitiveComponent* PrimitiveComponent1, int I, bool bArg, const FHitResult& HitResult);
	UFUNCTION()
	void OnEndOverlap(UPrimitiveComponent* PrimitiveComponent, AActor* Actor, UPrimitiveComponent* PrimitiveComponent1, int I);

	UFUNCTION(BlueprintCallable)
	void FireEverytimeForSecondTurret();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void OnHealthChanged(float CurrentHealth);
	
private:

	void FindNextTarget();
	void Fire();
	void Targeting();
	void OnDestroy();

	//хранение врагов//TWeakObjectPtr-это специальный указатель на объект, который может хранить указатель на "Actor" или на любой "UObject" и его наследники и при этом знать уничтожен ли этот объект или нет.
	//если мы уничтожим объект, TWeakObjectPtr<AActor> подскажет что данный объект, больше не существует.
	UPROPERTY()
	TArray<AActor*> OtherActors;
	TWeakObjectPtr<AActor> Target;
	
};