// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "UserWidget_Override.h"

#include "ItemDetails.generated.h"

class UTextBlock;
class URichTextBlock;
class UVerticalBox;
class UWidgetSwitcher;
class UScrollBox;

class UItemInteractionItem;
class UPropertyEntryDescription;

struct FBasicProxy;

UCLASS()
class PROJECT_API UItemDetails :
	public UUserWidget_Override
{
	GENERATED_BODY()

public:
	
	void Reset();	

	void BindData(
		const TSharedPtr<FBasicProxy>& ProxySPtr
		);

private:
	/**
	 * 0. 未选中
	 * 1. 选中
	 */
	UPROPERTY(meta = (BindWidget))
	UWidgetSwitcher* WidgetSwitcher = nullptr;

	UPROPERTY(meta = (BindWidget))
	UVerticalBox* InteractionVerticalBox = nullptr;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* NameText = nullptr;

	UPROPERTY(meta = (BindWidget))
	URichTextBlock* DescriptionText = nullptr;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UItemInteractionItem> InteractionItemClass;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UPropertyEntryDescription>PropertyEntryDescriptionClass;
	
	UPROPERTY(meta = (BindWidget))
	UScrollBox* PropertyEntrysBox = nullptr;
	
	TSharedPtr<FBasicProxy> PreviousProxySPtr = nullptr;
};
