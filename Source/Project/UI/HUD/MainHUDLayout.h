// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Blueprint/UserWidget.h"

#include "MainHUDLayout.generated.h"

class UCanvasPanel;
class UTextBlock;
class USizeBox;
class UOverlay;
class UButton;
class ASceneElementBase;
class UFeatureWheel;
class ASceneElement_Space;

UCLASS()
class PROJECT_API UMainHUDLayout : public UUserWidget
{
	GENERATED_BODY()

public:
	void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UOverlay* OverlapPtr = nullptr;

};
