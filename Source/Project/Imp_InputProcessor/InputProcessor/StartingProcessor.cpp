#include "StartingProcessor.h"

#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"

#include "GameOptions.h"
#include "GameplayTagsLibrary.h"
#include "PlanetPlayerController.h"
#include "PlayerGameplayTasks.h"
#include "AllocationPawn.h"
#include "TourPawn.h"

Processors::FStartingProcessor::FStartingProcessor(
	)
{
}

void Processors::FStartingProcessor::EnterAction()
{
	Super::EnterAction();
	
	SwitchShowCursor(true);
}

bool Processors::FStartingProcessor::InputKey(
	const FInputKeyEventArgs& EventArgs
	)
{
	return Super::InputKey(EventArgs);
}
