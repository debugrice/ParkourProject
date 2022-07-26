// Fill out your copyright notice in the Description page of Project Settings.


#include "ParkourComponent.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/WorldSettings.h"
#include "Engine/World.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/PrimitiveComponent.h"
#include "ParkourProjectCharacter.h"

// Sets default values for this component's properties
UParkourComponent::UParkourComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UParkourComponent::BeginPlay()
{
	Super::BeginPlay();
	ownerCharacter = Cast<AParkourProjectCharacter>(GetOwner());
	ownerMovementComponent = Cast<UPawnMovementComponent>(ownerCharacter->GetMovementComponent());
	
}


// Called every frame
void UParkourComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

// Called to determine what behavior the player shall undergo
void UParkourComponent::wallBehaviorDetermine()
{
	UE_LOG(LogTemp, Warning, TEXT("Test WallBehaviorDetermine function"));

	if (bIsWallFront())
	{
		climb();
	}


	//if (bIsLedgeFront())
	//{
	//	// Short Ledge Climb 
	//}

	//if (bIsGroundBelow())
	//{
	//	// Climb Down
	//}

	//if (bIsWallBeside())
	//{
	//	// Wall Run
	//}
}

// Called to check if there is a wall in front of the player
bool UParkourComponent::bIsWallFront()
{
	// Stores Player Location for starting point of Line Trace
	FVector PlayerLocation = (ownerCharacter->GetActorLocation());

	// Stores End Point of vector which is the player location + 100 times the forward vector of the player
	FVector fWallDetectLimit = PlayerLocation + ownerCharacter->GetActorForwardVector() * 300;

	// Output parameter for line trace
	FHitResult Hit;
	FCollisionQueryParams Params;
	
	// Since line begins from inside the character, a param is needed to avoid feedback from hitting the players collider
	Params.AddIgnoredActor(ownerCharacter);

	return (GetWorld()->LineTraceSingleByChannel(Hit, PlayerLocation, fWallDetectLimit, ECollisionChannel::ECC_GameTraceChannel1, Params));
}

//bool UParkourComponent::bIsWallBeside()
//{
//	UE_LOG(LogTemp, Warning, TEXT("Test bIsWallBeside"));
//	FVector PlayerLocation = (GetOwner()->GetActorLocation());
//	FRotator PlayerRotationLeft = (GetOwner()->GetActorRotation());
//	FRotator PlayerRotationRight = (GetOwner()->GetActorRotation());
//	PlayerRotationLeft.Yaw -= 45;
//	PlayerRotationRight.Yaw += 45;
//
//	UE_LOG(LogTemp, Warning, TEXT("Test PlayerRotationLeft: %s"), *PlayerRotationLeft.ToString());
//	UE_LOG(LogTemp, Warning, TEXT("Test PlayerRotationRight: %s"), *PlayerRotationRight.ToString());
//
//	FVector StartLocation = PlayerLocation + PlayerRotationLeft.Vector() * 1;
//	FVector leftWallDetectLimit = StartLocation + PlayerRotationLeft.Vector() * 100;
//	FVector rightWallDetectLimit = StartLocation + PlayerRotationRight.Vector() * 100;
//
//	UE_LOG(LogTemp, Warning, TEXT("Test Start Location: %s"), *StartLocation.ToString());
//	UE_LOG(LogTemp, Warning, TEXT("Test bIsWallBeside Left: %s"), *leftWallDetectLimit.ToString());
//	UE_LOG(LogTemp, Warning, TEXT("Test bIsWallBeside Right: %s"), *rightWallDetectLimit.ToString());
//
//	// LeftDrawDebug
//	DrawDebugLine(
//		GetWorld(),
//		PlayerLocation,
//		leftWallDetectLimit,
//		FColor::Red,
//		true,
//		10.0f,
//		0.0f,
//		10.0f);
//
//	DrawDebugLine(
//		GetWorld(),
//		PlayerLocation,
//		rightWallDetectLimit,
//		FColor::Red,
//		true,
//		10.0f,
//		0.0f,
//		10.0f);
//
//	return true;
//}
//
//
//bool UParkourComponent::bIsLedgeFront()
//{
//	UE_LOG(LogTemp, Warning, TEXT("Test IsLedgeFront"));
//
//	FVector PlayerLocation = (GetOwner()->GetActorLocation());
//	PlayerLocation.Z += 200;
//	UE_LOG(LogTemp, Warning, TEXT("The start point value is: %s"), *PlayerLocation.ToString());
//
//	FVector DetectLimit = PlayerLocation + GetOwner()->GetActorForwardVector() * 100;
//	FVector LedgeDetect = DetectLimit;
//	LedgeDetect.Z -= 100;
//	UE_LOG(LogTemp, Warning, TEXT("The DetectLimit value is: %s"), *DetectLimit.ToString());
//	FHitResult Hit;
//
//	DrawDebugLine(
//		GetWorld(),
//		DetectLimit,
//		LedgeDetect,
//		FColor::Red,
//		true,
//		10.0f,
//		0.0f,
//		10.0f);
//
//	return true;
//
//}
//
//bool UParkourComponent::bIsGroundBelow()
//{
//	UE_LOG(LogTemp, Warning, TEXT("Test bIsGroundBelow"));
//	FVector PlayerLocation = (GetOwner()->GetActorLocation());
//
//	FVector GroundBelowDetectLimit = PlayerLocation;
//	GroundBelowDetectLimit.Z -= 85;
//
//	DrawDebugLine(
//		GetWorld(),
//		PlayerLocation,
//		GroundBelowDetectLimit,
//		FColor::Red,
//		true,
//		10.0f,
//		0.0f,
//		10.0f);
//
//	return true;
//
//}
//

void UParkourComponent::climb()
{
	UE_LOG(LogTemp, Warning, TEXT("Test climb"));

	FVector PlayerLocation = (ownerCharacter->GetActorLocation());

	ownerCharacter->GetCharacterMovement()->AddImpulse(PlayerLocation + 500);

}


//void UParkourComponent::climbUp()
//{
//
//}
//void UParkourComponent::climbDown()
//{
//
//}
//void UParkourComponent::wallrun()
//{
//
//}
//void UParkourComponent::slide()
//{
//
//
//}