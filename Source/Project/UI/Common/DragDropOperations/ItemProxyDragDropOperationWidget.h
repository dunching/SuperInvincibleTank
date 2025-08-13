// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "UserWidget_Override.h"
#include "UIInterfaces.h"

#include "ItemProxyDragDropOperationWidget.generated.h"

class UUserWidget;

struct FBasicProxy;
struct FToolProxy;
struct FSkillProxy;
struct FConsumableProxy;
struct IProxy_Allocationble;

struct FStreamableHandle;

/**
 *
 */
UCLASS()
class PROJECT_API UItemProxyDragDropOperationWidget :
	public UUserWidget_Override
{
	GENERATED_BODY()

public:

	UItemProxyDragDropOperationWidget(const FObjectInitializer& ObjectInitializer);

	virtual void InvokeReset(UUserWidget* BaseWidgetPtr);

	virtual void ResetToolUIByData(const TSharedPtr<FBasicProxy>& BasicProxyPtr);

	virtual void EnableIcon(bool bIsEnable);

	void SetNum(int32 NewNum);

	void SetItemType(FBasicProxy* ToolSPtr);
	
	void ResetSize(const FVector2D& Size);

protected:

private:

	TSharedPtr<FBasicProxy> BasicProxyPtr = nullptr;

};

UCLASS()
class PROJECT_API UAllocationableProxyDragDropOperationWidget :
	public UUserWidget_Override
{
	GENERATED_BODY()

public:

	UAllocationableProxyDragDropOperationWidget(const FObjectInitializer& ObjectInitializer);

	virtual void InvokeReset(UUserWidget* BaseWidgetPtr);

	virtual void ResetToolUIByData(const TSharedPtr<FBasicProxy>& BasicProxyPtr);

	virtual void EnableIcon(bool bIsEnable);

	void SetNum(int32 NewNum);

	void SetItemType(FBasicProxy* ToolSPtr);
	
	void ResetSize(const FVector2D& Size);

protected:

private:

	TSharedPtr<IProxy_Allocationble> BasicProxyPtr = nullptr;

};
