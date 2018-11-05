// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include"Classes/Components/SphereComponent.h"
#include "Objective.generated.h"

UCLASS()
class FPSOBJ01_API AObjective : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObjective();
	UPROPERTY(VisibleAnywhere, Category = Components)
		USphereComponent * SphereComp;
	UPROPERTY(VisibleAnywhere, Category = Components)
		UStaticMeshComponent * MeshComp;
	UPROPERTY(EditDefaultsOnly, Category = Effects)
		UParticleSystem * ParticleEffects;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void AfterEffects();
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;


	
	
};
