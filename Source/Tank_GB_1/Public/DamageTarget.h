
#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DamageTarget.generated.h"

USTRUCT(BlueprintType)
struct FDamageData
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DamageValue;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* Instigator;
};

UINTERFACE(MinimalAPI)
class UDamageTarget : public UInterface
{
	GENERATED_BODY()                         
};                                           
/**
 *
 */

class TANK_GB_1_API IDamageTarget
{
	GENERATED_BODY()

public:
	
	virtual void TakeDamage(FDamageData Damage) = 0;
};