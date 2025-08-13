// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"

#include "GameplayTagContainer.h"

#include "AssetRefBase.h"
#include "GenerateTypes.h"

#include "AssetRefMap.generated.h"

class APlatformCharacter;
class AAllocationPawn;
class UItemProxyDragDropOperationWidget;
class UAllocationableProxyDragDropOperationWidget;
class UItemProxyDragDropOperation;

UCLASS(BlueprintType, Blueprintable)
class PROJECT_API UAssetRefMap : public UAssetRefBase
{
	GENERATED_BODY()

public:
	UAssetRefMap();

	static UAssetRefMap* GetInstance();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSoftObjectPtr<AAllocationPawn>AllocationPawnRef;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<FGameplayTag, TSubclassOf<APlatformCharacter>>PlatformCharacterMap;
	
#pragma region MenusUI
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "UI")
	TSubclassOf<UItemProxyDragDropOperationWidget>DragDropOperationWidgetClass;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "UI")
	TSubclassOf<UAllocationableProxyDragDropOperationWidget>AllocationableProxyDragDropOperationWidgetClass;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "UI")
	TSubclassOf<UItemProxyDragDropOperation>ItemsDragDropOperationClass;
#pragma endregion

};
