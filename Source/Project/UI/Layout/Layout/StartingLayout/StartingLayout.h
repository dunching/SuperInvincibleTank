// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "UserWidget_Override.h"
#include "LayoutWidgetBase.h"

#include "StartingLayout.generated.h"

class UMainHUDLayout;
class UOverlaySlot;
class UUserWidget;
class UButton;


/**
 *
 */
UCLASS()
class PROJECT_API UStartingLayout :
	public ULayoutWidgetBase
{
	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UButton* ButtonPtr = nullptr;

private:

	UFUNCTION()
	void OnClicked();

};
