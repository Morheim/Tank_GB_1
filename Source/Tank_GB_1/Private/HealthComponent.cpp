
#include "HealthComponent.h"
#include "Tank_GB_1/Parent class/ParentStarterClass.h"
#include "Tank_GB_1/Components/IScorable.h"

UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UHealthComponent::TakeDamage(FDamageData DamageData)
{
	float PrevValue = CurrentHealth;
	CurrentHealth -= DamageData.DamageValue;
	if (CurrentHealth < 0)
	{
		CurrentHealth = 0;
	}
	if(!FMath::IsNearlyEqual(PrevValue,CurrentHealth))
	{
		if(OnHealthChanged.IsBound())
			OnHealthChanged.Broadcast(CurrentHealth);
	}
	if (FMath::IsNearlyZero(CurrentHealth))
	{
		if (OnDestroy.IsBound())
			OnDestroy.Broadcast();
	}
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;
	
}
