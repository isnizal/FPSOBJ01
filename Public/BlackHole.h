// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include"Classes/Components/SphereComponent.h"
#include"Classes/Components/MeshComponent.h"
#include "BlackHole.generated.h"

UCLASS()
class FPSOBJ01_API ABlackHole : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlackHole();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION()
	void OverlapInnerSphere(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleAnywhere, Category = Component)
	UStaticMeshComponent * MeshComp;
	UPROPERTY(VisibleAnywhere, Category = Component)
	USphereComponent * InnerSphereComp;
	UPROPERTY(VisibleAnywhere, Category = Component)
	USphereComponent * OuterSphereComp;
	

	
	
};
