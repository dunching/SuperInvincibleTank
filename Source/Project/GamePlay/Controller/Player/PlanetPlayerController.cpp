#include "PlanetPlayerController.h"

#include "InputProcessorSubSystem_Imp.h"
#include "PlayerGameplayTasks.h"
#include "StartingProcessor.h"
#include "AllocationPawn.h"
#include "TourPawn.h"
#include "PixelStreamingInputComponent.h"

APlanetPlayerController::APlanetPlayerController(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{
	GameplayTasksComponentPtr = CreateDefaultSubobject<UPlayerControllerGameplayTasksComponent>(
		UPlayerControllerGameplayTasksComponent::ComponentName
	);
}

void APlanetPlayerController::BeginPlay()
{
	Super::BeginPlay();

#if UE_EDITOR || UE_CLIENT
	if (GetLocalRole() == ROLE_AutonomousProxy)
	{
		UInputProcessorSubSystem_Imp::GetInstance()->SwitchToProcessor<Processors::FStartingProcessor>(
			[this](
			auto NewProcessor
		)
			{
			}
		);
	}
#endif
}

void APlanetPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	bool bIsNewPawn = (InPawn != GetPawn());

	if (bIsNewPawn)
	{
	}
}

void APlanetPlayerController::OnRep_Pawn()
{
	Super::OnRep_Pawn();
}

void APlanetPlayerController::Possess_Server_Implementation(
	APawn* InPawn
	)
{
	Possess(InPawn);
}
