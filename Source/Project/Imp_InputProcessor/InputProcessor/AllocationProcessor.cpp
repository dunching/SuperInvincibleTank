#include "AllocationProcessor.h"

#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"

#include "GameOptions.h"
#include "AllocationPawn.h"
#include "AssetRefMap.h"
#include "GameplayTagsLibrary.h"
#include "PlanetPlayerController.h"
#include "StartignPawn.h"
#include "UIManagerSubSystem.h"
#include "HUD/MainHUDLayout.h"

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
		Cast<APlanetPlayerController>(GEngine->GetFirstLocalPlayerController(GetWorldImp()))->
			Possess_Server(TargetPawnPtr);
	}

	UUIManagerSubSystem::GetInstance()->GetMainHUDLayout()->SwitchLayout(UGameplayTagsLibrary::UI_Allocation);
}

bool Processors::FAllocationProcessor::InputKey(
	const FInputKeyEventArgs& EventArgs
	)
{
	return Super::InputKey(EventArgs);
}

void Processors::FAllocationProcessor::SelectedPlatformType(
	const FGameplayTag& PlatformTypeTag
	)
{
	if (PlatformTypeTag == CurrentPlatformTypeTag)
	{
		return;
	}

	if (CurrentPlatformCharacterPtr)
	{
		CurrentPlatformCharacterPtr->Destroy();
	}

	CurrentPlatformTypeTag = FGameplayTag::EmptyTag;
	
	if (PlatformTypeTag.MatchesTag(UGameplayTagsLibrary::Proxy_Platform_InLand))
	{
		if (PlatformTypeTag.MatchesTag(UGameplayTagsLibrary::Proxy_Platform_InLand_3X5))
		{
			if (UAssetRefMap::GetInstance()->PlatformCharacterMap.Contains(UGameplayTagsLibrary::Proxy_Platform_InLand_3X5))
			{
				CurrentPlatformTypeTag = PlatformTypeTag;
				CurrentPlatformCharacterPtr = GetWorldImp()->SpawnActor<APlatformCharacter>(
					UAssetRefMap::GetInstance()->PlatformCharacterMap[UGameplayTagsLibrary::Proxy_Platform_InLand_3X5],
					UAssetRefMap::GetInstance()->AllocationPawnRef->GetActorLocation(),
					FRotator::ZeroRotator
					);
			}
		}
		else if (PlatformTypeTag.MatchesTag(UGameplayTagsLibrary::Proxy_Platform_InLand_6X10))
		{
			if (UAssetRefMap::GetInstance()->PlatformCharacterMap.Contains(UGameplayTagsLibrary::Proxy_Platform_InLand_6X10))
			{
				CurrentPlatformTypeTag = PlatformTypeTag;
				CurrentPlatformCharacterPtr = GetWorldImp()->SpawnActor<APlatformCharacter>(
					UAssetRefMap::GetInstance()->PlatformCharacterMap[UGameplayTagsLibrary::Proxy_Platform_InLand_6X10],
					UAssetRefMap::GetInstance()->AllocationPawnRef->GetActorLocation(),
					FRotator::ZeroRotator
					);
			}
		}
	}
}
