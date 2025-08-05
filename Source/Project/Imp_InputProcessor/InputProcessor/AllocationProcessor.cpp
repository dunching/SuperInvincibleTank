#include "AllocationProcessor.h"

#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"

#include "GameOptions.h"
#include "AllocationPawn.h"
#include "AssetRefMap.h"
#include "PlanetPlayerController.h"
#include "TourPawn.h"

Processors::FAllocationProcessor::FAllocationProcessor(
	)
{
}

void Processors::FAllocationProcessor::EnterAction()
{
	FInputProcessor::EnterAction();

	SwitchShowCursor(true);

	auto TargetPawnPtr = UAssetRefMap::GetInstance()->AllocationPawnRef.LoadSynchronous();
	if (TargetPawnPtr)
	{
		Cast<APlanetPlayerController>(GEngine->GetFirstLocalPlayerController(GetWorldImp()))->Possess_Server(TargetPawnPtr);
	}
}

bool Processors::FAllocationProcessor::InputKey(
	const FInputKeyEventArgs& EventArgs
	)
{
	return Super::InputKey(EventArgs);
}
