// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

#include <AIController.h>

#include "GroupManaggerInterface.h"
#include "HumanCharacter_AI.h"
#include "PlanetControllerInterface.h"

#include "PlanetPlayerController.generated.h"

class UPlayerControllerGameplayTasksComponent;
class UPixelStreamingInput;
class AGroupManaggerImp;

/**
 *
 */
UCLASS()
class PROJECT_API APlanetPlayerController :
	public APlayerController,
	public IPlanetControllerInterface,
	public IGroupManaggerInterface
{
	GENERATED_BODY()

public:

	APlanetPlayerController(
		const FObjectInitializer& ObjectInitializer
		);

	virtual void PostInitializeComponents() override;

	virtual void BeginPlay() override;

	virtual void OnPossess(
		APawn* InPawn
		) override;
	
	virtual void OnRep_Pawn() override;
	
	virtual void GetLifetimeReplicatedProps(
		TArray<FLifetimeProperty>& OutLifetimeProps
		) const override;

	virtual AGroupManagger* GetGroupManagger() const override;

	virtual UInventoryComponent* GetInventoryComponent() const override;

#pragma region RPC
	UFUNCTION(Server,Reliable)
	void Possess_Server(APawn* InPawn);
	
	UFUNCTION(Server, Reliable)
	void AddProxy_Server(
		const FGameplayTag& ProxyType,
		int32 Num
		);

#pragma endregion 
	
	// 初始化共享信息相关的内容
	virtual void InitialGroupManagger();

	UFUNCTION()
	void OnRep_GroupManagger();

	UPROPERTY(ReplicatedUsing = OnRep_GroupManagger)
	TObjectPtr<AGroupManaggerImp> GroupManaggerPtr = nullptr;

	UPROPERTY()
	TObjectPtr<UPlayerControllerGameplayTasksComponent> GameplayTasksComponentPtr = nullptr;

};
