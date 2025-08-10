#include "PlayingProcessor.h"

#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"

#include "GameOptions.h"
#include "AllocationPawn.h"
#include "StartignPawn.h"

Processors::FPlayingProcessor::FPlayingProcessor(
	)
{
}

void Processors::FPlayingProcessor::EnterAction()
{
	FInputProcessor::EnterAction();

	SwitchShowCursor(true);
}

bool Processors::FPlayingProcessor::InputKey(
	const FInputKeyEventArgs& EventArgs
	)
{
	return Super::InputKey(EventArgs);
}
