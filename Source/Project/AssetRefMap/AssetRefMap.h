// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"

#include "GameplayTagContainer.h"

#include "AssetRefBase.h"
#include "GenerateTypes.h"

#include "AssetRefMap.generated.h"

UCLASS(BlueprintType, Blueprintable)
class PROJECT_API UAssetRefMap : public UAssetRefBase
{
	GENERATED_BODY()

public:
	UAssetRefMap();

	static UAssetRefMap* GetInstance();

};
