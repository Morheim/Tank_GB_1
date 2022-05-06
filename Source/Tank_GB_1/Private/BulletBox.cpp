
#include "BulletBox.h"

#include "Tank_Pawn.h"
#include "Components/StaticMeshComponent.h"

ABulletBox::ABulletBox()
{
	PrimaryActorTick.bCanEverTick = true;
	
	Collision = CreateDefaultSubobject<UBoxComponent>("Collision");
	RootComponent = Collision;

	Collision->OnComponentBeginOverlap.AddDynamic(this, &ABulletBox::OnBeginOverlap);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);

}
void ABulletBox::BeginPlay()
{
	Super::BeginPlay();
	
}
void ABulletBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABulletBox::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	auto Tank = Cast<ATank_Pawn>(OtherActor);
	if(Tank)
	{
		Tank->UploadAmmo(ShellCount);
	}
	if(!bInfinite)
	{
		Destroy();
	}
}