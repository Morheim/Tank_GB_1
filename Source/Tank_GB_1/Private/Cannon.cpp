// Fill out your copyright notice in the Description page of Project Settings.


#include "Cannon.h"

#include "DamageTarget.h"
#include "DrawDebugHelpers.h"
#include "Components/AudioComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ACannon::ACannon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>("RootComponent");

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);

	ProjectileSpawnPoint = CreateDefaultSubobject<UArrowComponent>("ProjectileSpawnPoint");
	ProjectileSpawnPoint->SetupAttachment(RootComponent);

	AudioEffect = CreateDefaultSubobject<UAudioComponent>("AudioEffect");
	AudioEffect->SetupAttachment(Mesh);

	ShootEffect = CreateDefaultSubobject<UParticleSystemComponent>("ShootEffect");
	ShootEffect->SetupAttachment(Mesh);
}

void ACannon::Shoot(int& AmmoTap)
{
	if (!bReadyToShoot)
		return;
	switch (Type)
	{
	case ECannonType::FireProjectile:
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Cyan, FString(TEXT("SHOOT")));
		GetWorld()->SpawnActor<ABaseProjectile>(ProjectileClass, ProjectileSpawnPoint->GetComponentLocation(), ProjectileSpawnPoint->GetComponentRotation());
		AmmoTap--;
		ShootEffect->ActivateSystem();
		AudioEffect->Play();
		GEngine->AddOnScreenDebugMessage(3, 666, FColor::Cyan, FString::Printf(TEXT("AMMOTAP - %i"),AmmoTap));

		if (CameraEffect)
		{
			GetWorld()->GetFirstPlayerController()->ClientStartCameraShake(CameraEffect);
		}
		if (ForceFeedbackEffect)
		{
			//для геймпада.
			FForceFeedbackParameters Parameters;
			Parameters.bLooping = false;
			GetWorld()->GetFirstPlayerController()->ClientPlayForceFeedback(ForceFeedbackEffect, Parameters);
		}
		break;
	case ECannonType::FireTrace:
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, FString(TEXT("TAPPED")));
		FHitResult Result;
		FCollisionObjectQueryParams Params;
		Params.AddObjectTypesToQuery(ECollisionChannel::ECC_Vehicle);
		Params.AddObjectTypesToQuery(ECollisionChannel::ECC_WorldDynamic);
		Params.AddObjectTypesToQuery(ECollisionChannel::ECC_WorldStatic);
		auto Start = ProjectileSpawnPoint->GetComponentLocation();
		auto End = Start + ProjectileSpawnPoint->GetForwardVector() * FireRange;
		bool HasHit = GetWorld()->LineTraceSingleByObjectType(
			Result,
			Start,
			End,
			Params);
		if (HasHit)
		{
		    End = Result.Location;
		    if (Result.Actor.IsValid())
		    {
		    	//Result.Actor->Destroy();
		    	auto Target = Cast<IDamageTarget>(Result.Actor);
		        if (Target)
		        {
		        	FDamageData DamageData;
		        	DamageData.Instigator = this;
		        	DamageData.DamageValue = LaserDamage;
			        Target->TakeDamage(DamageData);
		        }
		    }
			
		}
		
		DrawDebugLine(GetWorld(), Start, End, FColor::Black, false, 0.1, 0, 10);
		
		break;
	}
	bReadyToShoot = false;

	GetWorld()->GetTimerManager().SetTimer(TimerHandle,FTimerDelegate::CreateUObject(this, &ACannon::ResetShootState), 1/FireRate, false);
}

// Called when the game starts or when spawned
void ACannon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACannon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GEngine->AddOnScreenDebugMessage(12345, -1, FColor::Purple, FString::Printf(TEXT("RECHARDE %f"),GetWorld()->GetTimerManager().GetTimerElapsed(TimerHandle)));

}

void ACannon::ResetShootState()
{
	bReadyToShoot = true;
}