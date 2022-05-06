#pragma once

#include "CoreMinimal.h"
#include "DamageTarget.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANK_GB_1_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

	DECLARE_EVENT(UHealthComponent,FDieEvent)
	DECLARE_EVENT_OneParam(UHealthComponent,FHealthChanged, float)

public:
	UHealthComponent();

	void TakeDamage(FDamageData DamageData);
	
	float GetHeath() const
	{
		return CurrentHealth;
	}
	FDieEvent OnDestroy;
	FHealthChanged OnHealthChanged;
	
protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	float MaxHealth = 100;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	float CurrentHealth;
};