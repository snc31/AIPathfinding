// Fill out your copyright notice in the Description page of Project Settings.


#include "MainAIController.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"

void AMainAIController::BeginPlay()
{
	Super::BeginPlay();

	if (AIBehavior == nullptr)
	{
		return;
	}
	RunBehaviorTree(AIBehavior);
}

void AMainAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}