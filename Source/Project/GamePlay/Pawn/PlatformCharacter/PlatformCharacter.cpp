
#include "PlatformCharacter.h"

#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/PlayerInput.h"
#include "DrawDebugHelpers.h"
#include <Kismet/GameplayStatics.h>
#include <Subsystems/SubsystemBlueprintLibrary.h>
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "GameFramework/PlayerController.h"

#include "PlanetPlayerController.h"
#include "PlanetPlayerState.h"
#include "HumanAIController.h"
#include "SceneActorInteractionComponent.h"

APlatformCharacter::APlatformCharacter(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{
}

void APlatformCharacter::BeginPlay()
{
	Super::BeginPlay();

#if UE_EDITOR || UE_CLIENT
	if (GetNetMode() == NM_Client)
	{
		if (GetController())
		{
			if (GetController()->IsA(APlanetPlayerController::StaticClass()))
			{
			}
			else if (GetController()->IsA(AHumanAIController::StaticClass()))
			{
			}
		}
	}
#endif
}

void APlatformCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void APlatformCharacter::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
}

void APlatformCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (NewController->IsA(APlanetPlayerController::StaticClass()))
	{
	}
	else if (NewController->IsA(AHumanAIController::StaticClass()))
	{
	}
}

void APlatformCharacter::UnPossessed()
{
	Super::UnPossessed();
}
