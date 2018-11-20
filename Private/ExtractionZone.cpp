// Fill out your copyright notice in the Description page of Project Settings.

#include "ExtractionZone.h"


// Sets default values
AExtractionZone::AExtractionZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	OverlapComp = CreateDefaultSubobject<UBoxComponent>(FName("Box Component"));
	OverlapComp->SetBoxExtent(FVector(200.0f));
	OverlapComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	OverlapComp->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
	OverlapComp->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	RootComponent = OverlapComp;

	OverlapComp->OnComponentBeginOverlap.AddDynamic(this, &AExtractionZone::OverlapBox);


}

void AExtractionZone::OverlapBox(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Being extract"));
}

// Called when the game starts or when spawned
void AExtractionZone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AExtractionZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

