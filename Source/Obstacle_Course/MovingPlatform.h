// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLE_COURSE_API AMovingPlatform : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMovingPlatform();
	AMovingPlatform(const FObjectInitializer& ObjectInitializer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FVector _startLocation;
	float _distanceMoved;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Mesh Swap")
		UStaticMeshComponent* StaticMesh;
	UPROPERTY(EditAnywhere, Category = "Moving Platform")
		float _maxDistanceToMove = 100;
	UPROPERTY(EditAnywhere, Category = "Moving Platform")
		FVector _velocity = FVector(100, 0, 0);
};
