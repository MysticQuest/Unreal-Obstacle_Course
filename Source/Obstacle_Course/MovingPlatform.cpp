// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{


	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = ObjectInitializer.CreateOptionalDefaultSubobject<UStaticMeshComponent>(this, TEXT("NameYourComponentHere"));
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	_startLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector currentLocation = GetActorLocation();
	currentLocation = currentLocation + _velocity * DeltaTime;
	SetActorLocation(currentLocation);

	_distanceMoved = FVector::Dist(_startLocation, currentLocation);

	if (_distanceMoved > _maxDistanceToMove) 
	{
		FVector moveDirection = _velocity.GetSafeNormal();
		_startLocation = _startLocation + moveDirection * _maxDistanceToMove;
		SetActorLocation(_startLocation);
		_velocity = -_velocity;
	}
}