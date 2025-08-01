#include "PlayerGameplayTasks.h"

#include "DatasmithAssetUserData.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/StaticMeshActor.h"
#include "Tasks/AITask.h"
#include "Engine/Light.h"

#include "GameOptions.h"
#include "Algorithm.h"
#include "TourPawn.h"
#include "ViewerPawn.h"
#include "Tools.h"
#include "GameplayTagsLibrary.h"
#include "DatasmithSceneActor.h"
#include "GenerateTypes.h"
#include "LogWriter.h"
#include "ReplaceActor.h"
#include "TemplateHelper.h"
#include "CollisionDataStruct.h"

struct FPrefix : public TStructVariable<FPrefix>
{
	FName Datasmith_UniqueId = TEXT("Datasmith_UniqueId");
};

FName UPlayerControllerGameplayTasksComponent::ComponentName = TEXT("PlayerControllerGameplayTasksComponent");

void UPlayerControllerGameplayTasksComponent::OnGameplayTaskDeactivated(
	UGameplayTask& Task
	)
{
	Super::OnGameplayTaskDeactivated(Task);
}

void UGameplayTaskBase::OnDestroy(
	bool bInOwnerFinished
	)
{
	OnTaskComplete.Broadcast(true);

	Super::OnDestroy(bInOwnerFinished);
}
