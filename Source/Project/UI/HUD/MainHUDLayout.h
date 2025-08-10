// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Blueprint/UserWidget.h"
#include "GameplayTagContainer.h"

#include "MainHUDLayout.generated.h"

class UOverlay;
class UWidgetSwitcher;

UCLASS()
class PROJECT_API UMainHUDLayout : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	void SwitchLayout(const FGameplayTag&LayoutTag)const;
	
	UPROPERTY(meta = (BindWidget))
	UOverlay* OverlapPtr = nullptr;

	UPROPERTY(meta = (BindWidget))
	UWidgetSwitcher* WidgetSwitcherPtr = nullptr;

};
