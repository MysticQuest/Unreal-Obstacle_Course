// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

 //Sets default values
AMovingPlatform::AMovingPlatform(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = ObjectInitializer.CreateOptionalDefaultSubobject<UStaticMeshComponent>(this, TEXT("NameYourComponentHere"));
}

// Sets default values
//AMovingPlatform::AMovingPlatform()
//{
//	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
//	PrimaryActorTick.bCanEverTick = true;
//}

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
	MovePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime) 
{
	FVector currentLocation = GetActorLocation();
	currentLocation = currentLocation + _velocity * DeltaTime;
	SetActorLocation(currentLocation);
	_distanceMoved = FVector::Dist(_startLocation, currentLocation);

	ReversePlatform();
}

void AMovingPlatform::ReversePlatform()
{
	if (_distanceMoved > _maxDistanceToMove)
	{
		FVector moveDirection = _velocity.GetSafeNormal();
		_startLocation = _startLocation + moveDirection * _maxDistanceToMove;
		SetActorLocation(_startLocation);
		_initialVelocity = _velocity;
		_velocity = FVector(0, 0, 0);

		GetWorldTimerManager().SetTimer(TimerHandle, this, &AMovingPlatform::Timer, 1.f, true, 0.0);
	}
}

void AMovingPlatform::Timer()
{
	_timer++;
	if (_timer > _timerDelay) 
	{	
		_velocity = -_initialVelocity;
		_timer = 0;
	}
}