// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "ItemProxy.h"
#include "ItemProxy_Interface.h"
#include "Planet_ItemProxy.h"

#include "ItemProxy_PlatformExtension.generated.h"

class APlatformExtension;

UCLASS()
class PROJECT_API UItemProxy_Description_PlatformExtension : public UItemProxy_Description
{
	GENERATED_BODY()

public:
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	TSubclassOf<APlatformExtension> Consumable_Class;

};

/**
 * 平台扩展对象
 */
USTRUCT()
struct PROJECT_API FItemProxy_PlatformExtension :
	public FProject_BasicProxy,
	public IProxy_Allocationble
{
	GENERATED_USTRUCT_BODY()

public:
};

template <>
struct TStructOpsTypeTraits<FItemProxy_PlatformExtension> :
	public TStructOpsTypeTraitsBase2<FItemProxy_PlatformExtension>
{
	enum
	{
		WithNetSerializer = false,
	};
};
