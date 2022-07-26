// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ParkourComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PARKOURPROJECT_API UParkourComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UParkourComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

//	bool bIsWallBeside();
	bool bIsWallFront();
//	bool bIsLedgeFront();
//	bool bIsGroundBelow();
	bool bIsCharacterInJumpState();
	void climb();
//	void climbUp();
//	void climbDown();
//	void wallrun();
//	void slide();
//
	void wallBehaviorDetermine();
//
//private:
//	UPROPERTY(EditAnywhere)
//		float SenseRange = 1.5f;

	class AParkourProjectCharacter* ownerCharacter = nullptr;
	class UPawnMovementComponent* ownerMovementComponent = nullptr;
		
};
