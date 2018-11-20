// Fill out your copyright notice in the Description page of Project Settings.

#include "BlackHole.h"
#include"Classes/Components/MeshComponent.h"
#include"Classes/Components/SceneComponent.h"


// Sets default values
ABlackHole::ABlackHole()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//create object meshcomponent
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(FName("Mesh Components"));
	//assign as root component
	RootComponent = MeshComp;
	//set the mesh component to collision enable
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	//create object innersphere
	InnerSphereComp = CreateDefaultSubobject<USphereComponent>(FName("Inner Sphere"));
	//set radius inner sphere to be 50
	InnerSphereComp->SetSphereRadius(50);
	//set up as mesh comp root objects
	InnerSphereComp->SetupAttachment(MeshComp);
	//set to be overlap to destroy any primitive
	InnerSphereComp->OnComponentBeginOverlap.AddDynamic(this, &ABlackHole::OverlapInnerSphere);

	//create object overlap innersphere
	OuterSphereComp = CreateDefaultSubobject<USphereComponent>(FName("Out Sphere"));
	//set the radius to 5000
	OuterSphereComp->SetSphereRadius(5000);
	//set up overlap as attach to mesh comp root
	OuterSphereComp->SetupAttachment(MeshComp);
	


}


// Called when the game starts or when spawned
void ABlackHole::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABlackHole::OverlapInnerSphere(UPrimitiveComponent *OverlapComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
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
	//declare array of primitive overlap comp
	TArray<UPrimitiveComponent*>OverlapComps;
	//get the outer sphere component overlap to the overlap of array
	OuterSphereComp->GetOverlappingComponents(OverlapComps);
	//make loop for the overlap primitiv number
	for (int i = 0; i < OverlapComps.Num(); i++) {
		//declare new primitive component to be the overlap of primitive
		UPrimitiveComponent * PrimComp = OverlapComps[i];
		//declare branch of the prim to check is it simulate
		if (PrimComp &&PrimComp->IsSimulatingPhysics()) {
			//get the sphere radius of the outer sphere
			float GetOutSphere = OuterSphereComp->GetScaledSphereRadius();
			//declare float var to add force
			float AddForce = -5000.0f;
			//set the outer sphe to add radial force
			PrimComp->AddRadialForce(GetActorLocation(), GetOutSphere, AddForce, ERadialImpulseFalloff::RIF_MAX, true);
		}
	}

}

