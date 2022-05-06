// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AmmoBox.h"
#include "Cannon.h"
#include "TurretCannon.h"
#include "DamageTarget.h"
#include "SprayCannon.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Tank_GB_1/Parent class/ParentStarterClass.h"
#include "Tank_GB_1/Components/IScorable.h"
#include "Tank_Pawn.generated.h" 

class UStaticMeshComponent;
class UCameraComponent;
class USpringArmComponent;

UCLASS(Blueprintable)
class TANK_GB_1_API ATank_Pawn : public AParentStarterClass
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank_Pawn();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Components")
	USpringArmComponent* ArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Components")
	UCameraComponent* CameraComponent;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Fire params")
	TSubclassOf<ACannon> CannonType;
	UPROPERTY()
	ACannon* Cannon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category= "Fire parans")
	TSubclassOf<ATurretCannon>TurretCannonType;
	UPROPERTY()
	ATurretCannon* TurretCannon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Fire params")
	TSubclassOf<ASprayCannon> SprayCannonType;
	UPROPERTY()
	ASprayCannon* SprayCannon;
	
	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float MovementSpeed = 100;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float MovementAcceleration = 0.09;
	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float RotationSpeed = 90;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float RotationAcceleration = 0.09;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float TurretRotationAcceleration = 0.1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI|Move")
	FName WaypointTag;

	
	void MoveForward (float Scale);

	void RotateRight (float Scale);

	void Shoot();
	void SetupCannon(const TSubclassOf<ACannon>& CannonClass);

	
	void SprayShoot();
	void SetupCannonSpray(const TSubclassOf<ASprayCannon>& CannonClass);

	void TurretShoot();
	void TurretSetupCannon(const TSubclassOf<ATurretCannon>& CannonClass);
	
	void Swap();
	int SwapWep = 0;

	void UploadAmmo(const int ShellCount);
	
	virtual void TakeDamage(FDamageData Damage) override;
	
protected:
	virtual void BeginPlay() override;

	virtual void Destroyed() override;

public:	
	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void MoveTank(float DeltaTime);
	void RotateTank(float DeltaTime);
	void RotateCannon(float DeltaTime);
	void OnHealthChanged(float CurrentHealth);
	void OnDestroy();

	float MoveScaleTarget = 0;
	float MoveScaleCurrent = 0;
	float RotationScaleTarget = 0;
	float RotationScaleCurrent = 0;

	int AmmoTap = 155;
	int AmmoSpray = 1500;
	int AmmoTurret = 99999;

	//другой класс>>>>>>>>>>>>>>>>>>>>>>
	//int AmmoTurret;

	UPROPERTY()
	class ATank_PlayerController* TankController;
};