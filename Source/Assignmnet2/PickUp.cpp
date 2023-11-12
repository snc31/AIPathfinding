#include "PickUp.h"
#include "DrawDebugHelpers.h"
#include "Engine/world.h"
#include "GameFramework/PlayerController.h"

UPickUp::UPickUp()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UPickUp::BeginPlay()
{
	Super::BeginPlay();

	FindPhysicsHandle();
	ConfigureInputComponent();
}

void UPickUp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (PhysicsHandle->GrabbedComponent)
	{
		PhysicsHandle->SetTargetLocation(GetPlayersReach());
	}
}

void UPickUp::PickUp()
{
	FHitResult HitResult = GetFirstPhysicsBodyInReach();
	UPrimitiveComponent* ComponentToPickUp = HitResult.GetComponent();

	if (HitResult.GetActor())
	{
		PhysicsHandle->GrabComponentAtLocation(ComponentToPickUp, NAME_None, GetPlayersReach());
	}
}

void UPickUp::Release()
{
	PhysicsHandle->ReleaseComponent();
}

void UPickUp::FindPhysicsHandle()
{
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (PhysicsHandle == nullptr)
	{
		return;
	}
}

void UPickUp::ConfigureInputComponent()
{
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent == nullptr)
	{
		return;
	}
	InputComponent->BindAction("PickUp", IE_Pressed, this, &UPickUp::PickUp);
	InputComponent->BindAction("PickUp", IE_Released, this, &UPickUp::Release);
}

FHitResult UPickUp::GetFirstPhysicsBodyInReach() const
{
	FHitResult Hit;
	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());
	GetWorld()->LineTraceSingleByObjectType(Hit, GetPlayersWorldPos(), GetPlayersReach(), FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), TraceParams);

	//See what it hits
	AActor* ActorHit = Hit.GetActor();

	return Hit;
}

FVector UPickUp::GetPlayersReach() const
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewpointRotation;
	GetWorld()->GetFirstPlayerController()->GetActorEyesViewPoint(PlayerViewPointLocation, PlayerViewpointRotation);

	//Ray-Cast out to certain distance
	return PlayerViewPointLocation + PlayerViewpointRotation.Vector() * Reach;
}

FVector UPickUp::GetPlayersWorldPos() const
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewpointRotation;
	GetWorld()->GetFirstPlayerController()->GetActorEyesViewPoint(PlayerViewPointLocation, PlayerViewpointRotation);

	return PlayerViewPointLocation;
}