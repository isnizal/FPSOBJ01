// Fill out your copyright notice in the Description page of Project Settings.

#include "BlackHole.h"
#include"Classes/Components/MeshComponent.h"
#include"Classes/Components/SceneComponent.h"


// Sets default values
ABlackHole::ABlackHole()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create mesh comp 
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(FName("MeshComp"));
	//set collision enabled false
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	//Set mesh comp as root component
	RootComponent = MeshComp;

	//create inner sphere
	InnerSphereComp = CreateDefaultSubobject<USphereComponent>(FName("SphereComp"));
	//set inner sphere radius
	InnerSphereComp->SetSphereRadius(50);
	//attach to the mesh comp
	InnerSphereComp->SetupAttachment(MeshComp);
	//set inner sphere to become overlap sphere
	InnerSphereComp->OnComponentBeginOverlap.AddDynamic(this ,&ABlackHole::OverlapInnerSphere);

	//create outer sphere
	OuterSphereComp = CreateDefaultSubobject<USphereComponent>(FName("OuterSphereComp"));
	//attach to mesh comp
	OuterSphereComp->SetupAttachment(MeshComp);
	//set outer sphere radius
	OuterSphereComp->SetSphereRadius(5000);
	


}


// Called when the game starts or when spawned
void ABlackHole::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABlackHole::OverlapInnerSphere(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor)
	{
		OtherActor->Destroy();
	}
}


// Called every frame
void ABlackHole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Set declaring array of primitive component name overlapcomp
	TArray<UPrimitiveComponent*>OverlapComp;
	//Get outersphere to set with array of primitive component overlap
	OuterSphereComp->GetOverlappingComponents(OverlapComp);
	//Get loop through the array with overlap comp number
	for (int i = 0; i < OverlapComp.Num(); i++)
	{
		//Set the overlap comp looping of i with the primitive component
		UPrimitiveComponent * PrismComp = OverlapComp[i];
		//check to find if it simulating
		if (PrismComp && PrismComp->IsSimulatingPhysics())
		{
			//declaring variables float
			float AddForce = -5000;
			float GetRadius = OuterSphereComp->GetScaledSphereRadius();
			//adding the looping of overla component to add force
			PrismComp->AddRadialForce(GetActorLocation(), GetRadius, AddForce, ERadialImpulseFalloff::RIF_Constant, true);
		}
	}


}

