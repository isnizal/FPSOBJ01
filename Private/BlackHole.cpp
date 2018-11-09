// Fill out your copyright notice in the Description page of Project Settings.

#include "BlackHole.h"
#include"Classes/Components/MeshComponent.h"


// Sets default values
ABlackHole::ABlackHole()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(FName("MeshComponents"));
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = MeshComp;

	SphereComp = CreateDefaultSubobject<USphereComponent>(FName("SphereComponents"));
	SphereComp->SetSphereRadius(50);
	SphereComp->SetupAttachment(MeshComp);
	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &ABlackHole::OverlapInnerSphere);

	OuterSphereComp = CreateDefaultSubobject<USphereComponent>(FName("OuterSphereComponents"));
	OuterSphereComp->SetSphereRadius(3000);
	OuterSphereComp->SetupAttachment(MeshComp);

}
void ABlackHole::OverlapInnerSphere(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor)
	{
		OtherActor->Destroy();
	}
}


// Called when the game starts or when spawned
void ABlackHole::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABlackHole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TArray<UPrimitiveComponent*> OverlapComps;
	OuterSphereComp->GetOverlappingComponents(OverlapComps);

	for (int i = 0; i < OverlapComps.Num(); i++)
	{
		UPrimitiveComponent *PrimComp = OverlapComps[i];
		if (PrimComp && PrimComp->IsSimulatingPhysics())
		{
			float scaledRadius = OuterSphereComp->GetScaledSphereRadius();
			float ForceStrength = -5000;

			PrimComp->AddRadialForce(GetActorLocation(), scaledRadius, ForceStrength, ERadialImpulseFalloff::RIF_Constant, true);
		}
	}
}

