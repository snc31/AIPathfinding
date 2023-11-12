// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "PickUp.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASSIGNMNET2_API UPickUp : public UActorComponent
{
	GENERATED_BODY()

public:	
	UPickUp();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	float Reach = 800.f;	

	UPhysicsHandleComponent* PhysicsHandle;

	UInputComponent* InputComponent;

	void PickUp();
	void Release();
	void FindPhysicsHandle();
	void ConfigureInputComponent();
	FHitResult GetFirstPhysicsBodyInReach() const;
	FVector GetPlayersReach() const;
	FVector GetPlayersWorldPos() const;
};
