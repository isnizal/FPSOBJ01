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
	//declare function for overlap prim component
	UFUNCTION()
	void OverlapInnerSphere(UPrimitiveComponent *OverlapComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	void Tick(float DeltaTime);

public:	
	// Called every frame

	//declare variable innersphere
	UPROPERTY(VisibleAnywhere, Category = Components)
		USphereComponent * InnerSphereComp;
	//declare variable outersphere
	UPROPERTY(VisibleAnywhere, Category = Components)
		USphereComponent * OuterSphereComp;
	//declare variable mesh component
	UPROPERTY(VisibleAnywhere, Category = Components)
		UStaticMeshComponent * MeshComp;

	
	
};
