// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "InputProcessorSubSystemBase.h"
#include "PAD_ItemProxyCollection.h"

#include "PlanetWorldSettings.generated.h"

class UAssetRefMap;
class UStateTagExtendInfoMap;
class UDataTableCollection;
class UGameOptions;
class AGuideActor;
class AQuestChain_Main;
class AQuestChain_MainBase;
class UPAD_RewardsItems;
class UPAD_ItemProxyCollection;

/**
 *
 */
UCLASS()
class PROJECT_API APlanetWorldSettings :
	public AWorldSettings,
	public IGetInputProcessorSubSystemInterface,
	public IGetItemProxyCollectionInterface
{
	GENERATED_BODY()

public:

	virtual void PostInitializeComponents() override;

	virtual void BeginPlay() override;

	UAssetRefMap* GetAssetRefMapInstance()const;

	UDataTableCollection* GetSceneProxyExtendInfoMap()const;

	virtual UInputProcessorSubSystemBase* GetInputProcessorSubSystem()const override;
	
	virtual const UPAD_ItemProxyCollection*GetItemProxyCollection()const override;
	
protected:

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	TSoftObjectPtr<UAssetRefMap>AssetRefMapRef;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	TSoftObjectPtr<UDataTableCollection>SceneProxyExtendInfoMapPtr;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	TSoftObjectPtr<UPAD_ItemProxyCollection>PAD_ItemProxyCollectionRef;
	
};
