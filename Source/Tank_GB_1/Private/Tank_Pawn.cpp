// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank_Pawn.h"

#include "Tank_PlayerController.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Cannon.h"
#include "TurretCannon.h"
#include "SprayCannon.h"
#include "Kismet/KismetSystemLibrary.h"
#include "HealthComponent.h"
#include "Turret.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"


// Sets default values
ATank_Pawn::ATank_Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ArmComponent=CreateDefaultSubobject<USpringArmComponent>("ArmComponent");
	ArmComponent->SetupAttachment(RootComponent);


	CameraComponent=CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(ArmComponent);
	CameraComponent->bUsePawnControlRotation=false;

	
	DeadEffect = CreateDefaultSubobject<UParticleSystemComponent>("DeadEffect");
	DeadEffect->SetupAttachment(RootComponent);
	

	//HealthComponent = CreateDefaultSubobject<UHealthComponent>("HealthComponent");
	HealthComponent->OnHealthChanged.AddUObject(this, &ATank_Pawn::OnHealthChanged);
	HealthComponent->OnDestroy.AddUObject(this, &ATank_Pawn::OnDestroy);
}

void ATank_Pawn::MoveForward(float Scale)
{
	MoveScaleTarget = Scale;
}

void ATank_Pawn::RotateRight(float Scale)
{
	RotationScaleTarget = Scale;
}


void ATank_Pawn::Shoot()
{
	if(SwapWep == 0)
	{
		if (Cannon &&AmmoTap>0)
		{
			Cannon->Shoot(AmmoTap);
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(6, 2, FColor::Cyan, FString(TEXT("NOTHING AMMOTAP")));
		}
	}
	else
	{
		SprayShoot();
	}
}
void ATank_Pawn::SetupCannon(const TSubclassOf<ACannon>& CannonClass)
{
	CannonType = CannonClass;
	if (CannonType)
	{
		auto Transform = CannonPosition->GetComponentTransform();
		Cannon = GetWorld()->SpawnActor<ACannon>(CannonType, Transform);
		Cannon->AttachToComponent(CannonPosition, FAttachmentTransformRules::SnapToTargetIncludingScale);
	}
}

void ATank_Pawn::SprayShoot()
{
	if (SprayCannon &&AmmoSpray>0)
	{
		SprayCannon->SprayShoot(AmmoSpray);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(6, 2, FColor::Cyan, FString(TEXT("NOTHING AMMOSPRAY")));
	}
}
void ATank_Pawn::SetupCannonSpray(const TSubclassOf<ASprayCannon>& CannonClass)
{
	SprayCannonType = CannonClass;
	if (SprayCannonType)
	{
		auto Transform = CannonPosition->GetComponentTransform();
		SprayCannon = GetWorld()->SpawnActor<ASprayCannon>(SprayCannonType, Transform);
		SprayCannon->AttachToComponent(SprayCannonPosition, FAttachmentTransformRules::SnapToTargetIncludingScale);
	}
}

void ATank_Pawn::TurretShoot()
{
	
	if( TurretCannon != nullptr && AmmoTurret > 0)
	{
		TurretCannon->TurretShoot(AmmoTurret);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(3331, 1.5,FColor::Red,FString(TEXT("NO BULLET")));
	}
	
}


void ATank_Pawn::TurretSetupCannon(const TSubclassOf<ATurretCannon>& CannonClass)
{
	TurretCannonType = CannonClass;
	if(TurretCannonType)
	{
		auto Transform = CannonPosition->GetComponentTransform();
		TurretCannon = GetWorld()->SpawnActor<ATurretCannon>(TurretCannonType, Transform);
		TurretCannon->AttachToComponent(CannonPosition,FAttachmentTransformRules::SnapToTargetIncludingScale);
	}
}

void ATank_Pawn::Swap()
{
	if (SwapWep == 0)
	{
		SwapWep = 1;
	}
	else
	{
		SwapWep = 0;
	}
}

void ATank_Pawn::UploadAmmo(const int ShellCount)
{
	AmmoTap += ShellCount;
	GEngine->AddOnScreenDebugMessage(1234, 999999, FColor::Blue, FString::Printf(TEXT("AmmoBB - %i"), AmmoTap));
	
	AmmoSpray += ShellCount;
	GEngine->AddOnScreenDebugMessage(1235, 999999, FColor::Blue, FString::Printf(TEXT("AmmoAK - %i"), AmmoSpray));
}

void ATank_Pawn::TakeDamage(FDamageData Damage)
{
	if (HealthComponent)
		HealthComponent->TakeDamage(Damage);
}

// Called when the game starts or when spawned
void ATank_Pawn::BeginPlay()
{
	Super::BeginPlay();


	TankController = Cast<ATank_PlayerController>(GetController());
	
	//SetupCannon(CannonType);
	//SetupCannonSpray(SprayCannonType);
	
	/*if(IsValid(GameOverWidgetClass))
		{
			GameOverWidget = CreateWidget(GetWorld(), GameOverWidgetClass);
		}*/
		
	if (CannonType)
    	{
    		auto Transform = CannonPosition->GetComponentTransform();
    		Cannon = GetWorld()->SpawnActor<ACannon>(CannonType, Transform);
    		Cannon->AttachToComponent(CannonPosition, FAttachmentTransformRules::SnapToTargetIncludingScale);
    	}
	if (SprayCannonType)
    	{
    		auto Transform = SprayCannonPosition->GetComponentTransform();
    		SprayCannon = GetWorld()->SpawnActor<ASprayCannon>(SprayCannonType, Transform);
    		SprayCannon->AttachToComponent(SprayCannonPosition, FAttachmentTransformRules::SnapToTargetIncludingScale);
		}
}

void ATank_Pawn::Destroyed()
{
	Super::Destroyed();

	if (Cannon)
	{
		Cannon->Destroy();
	}
	if (SprayCannon)
	{
		SprayCannon->Destroy();
	}
	if(TurretCannon)
	{
		TurretCannon->Destroy();
	}
}

// Called every frame
void ATank_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	MoveTank(DeltaTime);
	RotateTank(DeltaTime);
	RotateCannon(DeltaTime);

}

// Called to bind functionality to input
void ATank_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank_Pawn::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	TankController = Cast<ATank_PlayerController>(GetController());
}

void ATank_Pawn::MoveTank(float DeltaTime)
{
	MoveScaleCurrent = FMath::Lerp(MoveScaleCurrent, MoveScaleTarget, MovementAcceleration);
	const auto Location = GetActorLocation();
	SetActorLocation(Location + GetActorForwardVector() * MoveScaleCurrent * MovementSpeed * DeltaTime, false);
	
	//отображает на экране скорость танка в виде строчки когда
	GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Cyan, FString::Printf(TEXT("%f"), MoveScaleCurrent));
	
}

void ATank_Pawn::RotateTank(float DeltaTime)
{
	RotationScaleCurrent = FMath::Lerp(RotationScaleCurrent, RotationScaleTarget, RotationAcceleration);
	auto Rotation = GetActorRotation();
	Rotation.Yaw += RotationScaleCurrent * RotationSpeed * DeltaTime;
	SetActorRotation(Rotation);
	
}

void ATank_Pawn::RotateCannon(float DeltaTime)
{
	if (!TankController)
		return;
	auto BodyMeshRotation = BodyMesh->GetComponentRotation();
	auto OldRotation = TurretMesh->GetComponentRotation();
	FRotator TurretRotation =  UKismetMathLibrary::FindLookAtRotation(TurretMesh->GetComponentLocation(), TankController->GetMousePosition());
	OldRotation.Yaw = TurretRotation.Yaw;
	OldRotation.Pitch = BodyMeshRotation.Pitch;
	OldRotation.Roll = BodyMeshRotation.Roll;
	TurretMesh->SetWorldRotation(FMath::Lerp(TurretMesh->GetComponentRotation(), OldRotation, TurretRotationAcceleration));
}

void ATank_Pawn::OnHealthChanged(float CurrentHealth)
{
	GEngine->AddOnScreenDebugMessage(237679870, 10, FColor::Red, FString::Printf(TEXT("Health: %f"), CurrentHealth));
}

void ATank_Pawn::OnDestroy()
{

	DeadEffect->ActivateSystem();

	if(IsValid(GameOverWidgetClass))
	{
		GameOverWidget = CreateWidget(GetWorld(), GameOverWidgetClass);
		GameOverWidget->AddToViewport();
	}
	
	GetWorld()->GetTimerManager().SetTimer(QuitGame, this,&ATank_Pawn::QuitGameStopSimulation, QuitGameSec, true);
	
	Destroy();
}


void ATank_Pawn::QuitGameStopSimulation()
{
	UKismetSystemLibrary::QuitGame(GetWorld(),GetWorld()->GetFirstPlayerController(),EQuitPreference::Quit,true);
}


