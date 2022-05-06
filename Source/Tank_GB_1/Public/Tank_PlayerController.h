// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank_Pawn.h"
#include "EnemyTank_Pawn.h"
#include "TargetController.h"
#include "GameFramework/PlayerController.h"
#include "Tank_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANK_GB_1_API ATank_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	
	virtual void SetupInputComponent() override;
	
	void OnMoveForward (float Value);
	void OnRotateRight (float Value);
	void OnShoot();
	void OnSprayShoot();
	void OnTurretShoot();

	void OnSwapWeapon();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	FVector GetMousePosition() const { return MouseWorldPosition; }
	
private:
	UPROPERTY()
	ATank_Pawn* PlayerTank;
	
	FVector MouseWorldPosition;
	
};