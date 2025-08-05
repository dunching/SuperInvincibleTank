// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

#include <AIController.h>

#include "HumanCharacter_AI.h"
#include "PlanetControllerInterface.h"

#include "PlanetPlayerController.generated.h"

class UPlayerControllerGameplayTasksComponent;
class UPixelStreamingInput;

/**
 *
 */
UCLASS()
class PROJECT_API APlanetPlayerController :
	public APlayerController,
	public IPlanetControllerInterface
{
	GENERATED_BODY()

public:

	APlanetPlayerController(
		const FObjectInitializer& ObjectInitializer
		);

	virtual void BeginPlay() override;

	virtual void OnPossess(
		APawn* InPawn
		) override;
	
	virtual void OnRep_Pawn() override;

#pragma region RPC
	UFUNCTION(Server,Reliable)
	void Possess_Server(APawn* InPawn);
#pragma endregion 
	
	UPROPERTY()
	TObjectPtr<UPlayerControllerGameplayTasksComponent> GameplayTasksComponentPtr = nullptr;

};
