// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include"Classes/Components/BoxComponent.h"
#include "ExtractionZone.generated.h"

UCLASS()
class FPSOBJ01_API AExtractionZone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AExtractionZone();
	UFUNCTION()
	void OverlapBox(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

protected:
public:	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UBoxComponent * OverlapComp;
	
	
};
