// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

#include "GameFramework/Character.h"

#include "PlatformExtension.generated.h"

UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class PROJECT_API UPlatformExtensionAnchor :
	public USceneComponent
{
	GENERATED_BODY()

public:
	
};

/**
 * 平台扩展组件类型
 */
UCLASS()
class PROJECT_API APlatformExtension :
	public AActor
{
	GENERATED_BODY()

public:

	/**
	 * 可以放置的锚点
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FGameplayTag PlatformExtensionType;
	
};
