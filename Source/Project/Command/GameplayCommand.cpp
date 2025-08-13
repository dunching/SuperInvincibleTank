#include "GameplayCommand.h"

#include "Kismet/KismetStringLibrary.h"
#include "Kismet/GameplayStatics.h"

#include "PlanetPlayerController.h"
#include "Tools.h"

void GameplayCommand::AddProxy(
	const TArray<FString>& Args
	)
{
#if WITH_EDITOR
	if (!Args.IsValidIndex(1))
	{
		return;
	}

	auto PCPtr = Cast<APlanetPlayerController>(UGameplayStatics::GetPlayerController(GetWorldImp(), 0));
	if (PCPtr)
	{
		PCPtr->AddProxy_Server(
		                       FGameplayTag::RequestGameplayTag(*Args[0]),
		                       UKismetStringLibrary::Conv_StringToInt(Args[1])
		                      );
	}
#endif
}
