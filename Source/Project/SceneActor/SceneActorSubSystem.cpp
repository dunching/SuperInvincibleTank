
#include "SceneActorSubSystem.h"

#include <Subsystems/SubsystemBlueprintLibrary.h>
#include <Kismet/GameplayStatics.h>

#include "AssetRefMap.h"
#include "Tools.h"

USceneActorSubSystem* USceneActorSubSystem::GetInstance()
{
	return Cast<USceneActorSubSystem>(USubsystemBlueprintLibrary::GetGameInstanceSubsystem(
		GetWorldImp(), USceneActorSubSystem::StaticClass())
	);
}

APostProcessVolume* USceneActorSubSystem::GetSkillPost() const
{
	APostProcessVolume * ResultPtr = nullptr;

	return ResultPtr;
}

