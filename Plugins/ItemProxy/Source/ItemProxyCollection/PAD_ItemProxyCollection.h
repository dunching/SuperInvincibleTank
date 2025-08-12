// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"

#include "GameplayTagContainer.h"

#include "ItemProxy_Descriptions.h"
#include "ItemProxy_GenericType.h"

#include "PAD_ItemProxyCollection.generated.h"

class UDataTable;
class UPAD_Talent_Property;
class UItemDecriptionBaseWidget;
class UItemProxy_Description;

struct FToolProxy;
struct FWeaponProxyBase;
struct FSkillProxy;
struct FCoinProxyBase;
struct FBasicProxy;

struct FTableRowProxy_TagExtendInfo;
struct FTableRowProxy_CharacterGrowthAttribute;
struct FTableRow_Regions;

UCLASS(BlueprintType, Blueprintable)
class ITEMPROXY_API UPAD_ItemProxyCollection : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	static const UPAD_ItemProxyCollection* GetInstance();
	
	const FProxyDescriptionHelper GetTableRowProxy(FGameplayTag ProxyType)const;

	/**
	 * 可被持有的“物品”基础信息
	 */
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "UnitExtendInfoMap")
	TMap<FGameplayTag,FProxyDescriptionHelper> ProxyDescriptionMap;
};

UINTERFACE(MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UGetItemProxyCollectionInterface : public UInterface
{
	GENERATED_BODY()
};

class ITEMPROXY_API IGetItemProxyCollectionInterface
{
	GENERATED_BODY()

public:
	virtual const UPAD_ItemProxyCollection*GetItemProxyCollection()const = 0;
	
};
