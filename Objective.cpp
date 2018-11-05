// Fill out your copyright notice in the Description page of Project Settings.

#include "Objective.h"
#include"Classes/Components/StaticMeshComponent.h"
#include"Classes/Kismet/GameplayStatics.h"
#include"FPSOBJ01Character.h"


// Sets default values
AObjective::AObjective()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetupAttachment(MeshComp);
	SphereComp->SetSphereRadius(50.0f);
	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	SphereComp->SetCollisionResponseToChannel(ECC_Pawn,ECR_Overlap);
}

// Called when the game starts or when spawned
void AObjective::BeginPlay()
{
	Super::BeginPlay();
	AfterEffects();
	
}

// Called every frame
void AObjective::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AObjective::AfterEffects()
{
	UGameplayStatics::SpawnEmitterAtLocation(this, ParticleEffects,GetActorLocation());
}

void AObjective::NotifyActorBeginOverlap(AActor * OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	AfterEffects();
	AFPSOBJ01Character * Actor = Cast<AFPSOBJ01Character>(OtherActor);
	if (Actor)
	{
		Actor->isCarryingObjective = true;
	}
	Destroy();
}

