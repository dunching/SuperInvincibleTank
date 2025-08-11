// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameplayTagContainer.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"

#include "PlatformSocketComponent.generated.h"

class UBoxComponent;
class UBillboardComponent;

/**
 * 平台组件插槽
 */
UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class PROJECT_API UPlatformSocketComponent :
	public UBoxComponent
{
	GENERATED_BODY()

public:
	
	UPlatformSocketComponent(const FObjectInitializer& ObjectInitializer);
	
	/**
	 * 可以放置的扩展组件类型
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FGameplayTagContainer CanPlagPlatformType;
	
#if WITH_EDITORONLY_DATA
	/** Component shown in the editor only to indicate character facing */
	UPROPERTY()
	TObjectPtr<UBillboardComponent> BillboardComponent;
#endif

};