// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include <functional>
#include <map>
#include <set>

#include "CoreMinimal.h"

#include "GameplayTagContainer.h"

#include "GameplayTasksComponent.h"
#include "GenerateTypes.h"

#include "PlayerGameplayTasks.generated.h"

class AAllocationPawn;
class USceneInteractionWorldSystem;
class ADatasmithSceneActor;
class AReplaceActor;

class UGameplayTaskBase;

/*
 * PlayerController处理异步的组件
 */
UCLASS(
	BlueprintType,
	Blueprintable
)
class PROJECT_API UPlayerControllerGameplayTasksComponent : public UGameplayTasksComponent
{
	GENERATED_BODY()

public:
	static FName ComponentName;
	
	virtual void OnGameplayTaskDeactivated(UGameplayTask& Task) override;
	
	template <typename GameplayTaskType>
	void StartGameplayTask(
		const std::function<void(
			GameplayTaskType*


			
			)>& Func
		);
};

template <typename GameplayTaskType>
void UPlayerControllerGameplayTasksComponent::StartGameplayTask(
	const std::function<void(
		GameplayTaskType*
		)>& Func
	)
{
	auto GameplayTaskPtr = UGameplayTask::NewTask<GameplayTaskType>(
	                                                                TScriptInterface<
		                                                                IGameplayTaskOwnerInterface>(
		                                                                 this
		                                                                )
	                                                               );

	if (Func)
	{
		Func(GameplayTaskPtr);
	}

	GameplayTaskPtr->ReadyForActivation();
}


UCLASS()
class PROJECT_API UGameplayTaskBase : public UGameplayTask
{
	GENERATED_BODY()

public:
	class UPlayerControllerGameplayTasksComponent;
	
	using FOnTaskComplete = TMulticastDelegate<void(
		bool
		)>;

	virtual void OnDestroy(
		bool bInOwnerFinished
		) override;

	UPROPERTY()
	TObjectPtr<UGameplayTaskBase> NextTaskPtr;
	
protected:
	
	FOnTaskComplete OnTaskComplete;
};
