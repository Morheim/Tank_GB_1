#pragma once

#include "CoreMinimal.h"
#include "DamageTarget.h"
//#include "EnemyAIController.h"
#include "TurretCannon.h"
#include  "Turret.h"
#include "Engine/TargetPoint.h"
#include "TANK_GB_1/Parent class/ParentStarterClass.h"
#include "EnemyTank_Pawn.generated.h"


UCLASS(Blueprintable)
class TANK_GB_1_API AEnemyTank_Pawn : public AParentStarterClass
{
	GENERATED_BODY()

public:
	
	// Sets default values for this pawn's properties
	AEnemyTank_Pawn();


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USphereComponent* RangeSphere;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category= "Fire parans")
	TSubclassOf<ATurretCannon>TurretCannonType;

	UPROPERTY()
	ATurretCannon* TurretCannon;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
	float MovementSpeed = 600;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement")
	float MovementAcceleration = 0.06;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement")
	float RotationSpeed = 90;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement")
	float RotationAcceleration = 0.06;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement")
	float TurretAcceleration = 0.1;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AI|Move")
	FName WaypointTag;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AI|Move")
	TArray<ATargetPoint*> Waypoints;
	
	
	UPROPERTY()
	class AEnemyAIController* EnemyAITankController;
	
	UPROPERTY()
	TArray<AActor*> OtherActors;
	
	virtual void OnConstruction(const FTransform& Transform) override;

	int Number = -1;
	
	void MoveForward(float Scale);
	void RotateRight(float Scale);
	
	void TurretShoot();
	void TurretSetupCannon(const TSubclassOf<ATurretCannon>& CannonClass);
	
	virtual void TakeDamage(FDamageData Damage) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	virtual void PossessedBy(AController* NewController) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Destroyed() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

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
	
	UFUNCTION()
virtual void OnBeginOverlap(UPrimitiveComponent* PrimitiveComponent, AActor* Actor,
UPrimitiveComponent* OtherComponent, int I, bool bArg, const FHitResult& HitResult);

	UFUNCTION()
	void OnEndOverlap(UPrimitiveComponent* PrimitiveComponent, AActor* Actor,
		UPrimitiveComponent* OtherComponent, int I);
	int AmmoII = 100;

	
	TWeakObjectPtr<AActor> Target;
	
	class ITargetController* TargetController;
	
};