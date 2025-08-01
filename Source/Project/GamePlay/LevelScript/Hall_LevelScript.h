// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "CoreMinimal.h"

#include "Engine/LevelScriptActor.h"

#include "Hall_LevelScript.generated.h"

/**
 * 大厅
 */
UCLASS()
class PROJECT_API AHall_LevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()

public:

	virtual void BeginPlay()override;

};

/**
 * 开放世界
 */ 
UCLASS()
class PROJECT_API AMain_LevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()

public:

	virtual void BeginPlay()override;

	void ClearWorldProcessCache();
	
};
