// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Blueprint/IUserObjectListEntry.h>

#include "UIInterfaces.h"
#include "GenerateTypes.h"
#include "ItemProxy_Minimal.h"
#include "UserWidget_Override.h"

#include "BackpackIconWrapper.generated.h"

struct FStreamableHandle;

struct FBasicProxy;
struct IProxy_Allocationble;
struct FToolProxy;

class UBackpackConsumableIcon;
class UBackpackToolIcon;
class UBackpackSkillIcon;
class UBackpackWeaponIcon;
class UBackpackMaterialIcon;
class UAllocationSkillsMenu;

/**
 *
 */
UCLASS()
class PROJECT_API UBackpackIconWrapper :
	public UUserWidget_Override,
	public IUserObjectListEntry
{
	GENERATED_BODY()

public:

	UBackpackIconWrapper(const FObjectInitializer& ObjectInitializer);

	virtual void NativeOnListItemObjectSet(UObject* ListItemObject)override;

	virtual void InvokeReset(UUserWidget* BaseWidgetPtr);

	virtual void ResetToolUIByData(const TSharedPtr<FBasicProxy>& BasicProxyPtr);

	virtual void EnableIcon(bool bIsEnable);

	TSharedPtr<FBasicProxy> TargetBasicProxyPtr = nullptr;

	UAllocationSkillsMenu * AllocationSkillsMenuPtr= nullptr;
	
protected:

};
