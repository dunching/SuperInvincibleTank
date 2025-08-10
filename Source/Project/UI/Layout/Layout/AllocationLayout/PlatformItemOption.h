// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "UserWidget_Override.h"
#include "LayoutWidgetBase.h"

#include "PlatformItemOption.generated.h"

class UTextBlock;
class UMainHUDLayout;
class UOverlaySlot;
class UUserWidget;
class UButton;


/**
 *
 */
UCLASS()
class PROJECT_API UPlatformItemOption :
	public UUserWidget_Override
{
	GENERATED_BODY()

public:
	virtual void NativePreConstruct() override;
	
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UButton* ButtonPtr = nullptr;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextPtr = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Text;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag PlatformTypeTag;

private:
	UFUNCTION()
	void OnClicked();
};
