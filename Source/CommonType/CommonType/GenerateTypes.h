// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <functional>

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

#include "GenerateTypes.generated.h"

class ADatasmithSceneActor;
class AReplaceActor;
class ASceneElementBase;

UENUM()
enum class EOperatorType: uint8
{
	kLeftMouseButton,

	kRightMouseButton,

	kNone,
};

USTRUCT(BlueprintType, Blueprintable)
struct COMMONTYPE_API FModeDecription
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FString Title;
};

USTRUCT(BlueprintType, Blueprintable)
struct COMMONTYPE_API FSceneElementTypeHelper
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FString Key;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FString Value;
};

struct COMMONTYPE_API TFSceneElementTypeHelperKeyFuncs :
	BaseKeyFuncs<
		FSceneElementTypeHelper, FSceneElementTypeHelper,
		false
	>
{
private:
	typedef BaseKeyFuncs<
		FSceneElementTypeHelper, FSceneElementTypeHelper,
		false
	> Super;

public:
	typedef typename Super::ElementInitType ElementInitType;
	typedef typename Super::KeyInitType KeyInitType;

	static KeyInitType GetSetKey(
		ElementInitType Element
		);

	static bool Matches(
		KeyInitType A,
		KeyInitType B
		);

	static uint32 GetKeyHash(
		KeyInitType Key
		);
};

COMMONTYPE_API uint32 GetTypeHash(
	const FSceneElementTypeHelper& SceneElementTypeHelper
	);

USTRUCT(BlueprintType, Blueprintable)
struct COMMONTYPE_API FSceneElementMap
{
	GENERATED_BODY()

	/**
	 * 硬装，结构
	 */
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	TSet<TSoftObjectPtr<ADatasmithSceneActor>> StructItemSet;
	
	/**
	 * 硬装，内饰
	 */
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	TSet<TSoftObjectPtr<ADatasmithSceneActor>> InnerStructItemSet;
	
	/**
	 * 软装，如电气
	 */
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	TSet<TSoftObjectPtr<ADatasmithSceneActor>> SoftDecorationItemSet;
	
	/**
	 * 软装，如电气
	 */
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	TSet<TSoftObjectPtr<AReplaceActor>> ReplaceSoftDecorationItemSet;
	
	/**
	 * 空间区域
	 */
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	TSet<TSoftObjectPtr<ADatasmithSceneActor>> SpaceItemSet;
	
};

/**
 * 条件
 */
USTRUCT(Blueprintable, BlueprintType)
struct COMMONTYPE_API FSceneElementConditional
{
	GENERATED_BODY()

	FSceneElementConditional();;

	FSceneElementConditional(
		const TSet<FGameplayTag>& InConditionalSet
		);

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FGameplayTagContainer ConditionalSet;
};

struct COMMONTYPE_API TSceneElementConditionalKeyFuncs :
	BaseKeyFuncs<
		FSceneElementConditional, FSceneElementConditional,
		false
	>
{
private:
	typedef BaseKeyFuncs<
		FSceneElementConditional, FSceneElementConditional,
		false
	> Super;

public:
	typedef typename Super::ElementInitType ElementInitType;
	typedef typename Super::KeyInitType KeyInitType;

	static KeyInitType GetSetKey(
		ElementInitType Element
		);

	static bool Matches(
		KeyInitType A,
		KeyInitType B
		);

	static uint32 GetKeyHash(
		KeyInitType Key
		);
};

COMMONTYPE_API uint32 GetTypeHash(
	const FSceneElementConditional& SceneActorConditional
	);
