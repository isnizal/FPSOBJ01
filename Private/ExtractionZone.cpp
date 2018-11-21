// Fill out your copyright notice in the Description page of Project Settings.

#include "ExtractionZone.h"
#include"Classes/Components/DecalComponent.h"


// Sets default values
AExtractionZone::AExtractionZone()
{
	OverlapComp = CreateDefaultSubobject<UBoxComponent>(FName("Box Component"));
	OverlapComp->SetBoxExtent(FVector(100));
	OverlapComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	OverlapComp->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	OverlapComp->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
	RootComponent = OverlapComp;
	OverlapComp->SetHiddenInGame(false);

	OverlapComp->OnComponentBeginOverlap.AddDynamic(this, &AExtractionZone::OverlapBox);

	DecalComp = CreateDefaultSubobject<UDecalComponent>(FName("Decal Component"));
	DecalComp->DecalSize = FVector(100, 100, 100);

	DecalComp->SetupAttachment(RootComponent);

}

void AExtractionZone::OverlapBox(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("Being extract"));
	}
	
}
