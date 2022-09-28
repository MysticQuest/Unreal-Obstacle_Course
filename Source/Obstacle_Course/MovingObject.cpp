// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingObject.h"

// Sets default values
AMovingObject::AMovingObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingObject::BeginPlay()
{
	Super::BeginPlay();
	
	//_startLocation = GetActorLocation();
}

// Called every frame
void AMovingObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//FVector currentLocation = GetActorLocation();
	//currentLocation = currentLocation + _velocity * DeltaTime;
	//SetActorLocation(currentLocation);

	//_distanceMoved = FVector::Dist(_startLocation, currentLocation);

	//if (_distanceMoved > _maxDistanceToMove)
	//{
	//	FVector moveDirection = _velocity.GetSafeNormal();
	//	_startLocation = _startLocation + moveDirection * _maxDistanceToMove;
	//	SetActorLocation(_startLocation);
	//	_initialVelocity = _velocity;
	//	_velocity = FVector(0, 0, 0);

	//	_timer += FDateTime::UtcNow().GetMillisecond() / 1000;

	//	if (_timer < _timerDelay)
	//	{
	//		_velocity = -_initialVelocity;
	//		_timer = 0;
	//	}
	//}
}

