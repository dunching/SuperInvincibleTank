// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <bitset>

#include "CoreMinimal.h"

#include "UIInterfaces.h"

#include "GenerateTypes.h"
#include "ItemProxy_Minimal.h"

#include "UserWidget_Override.h"
#include "BackpackMenu.generated.h"

class UBackpackConsumableIcon;
class UBackpackToolIcon;
class UAllocationSkillsMenu;
class UButton;

struct FSceneObjContainer;
struct FSceneProxyContainer;
struct FSkillProxy;
struct FCharacterProxy;
struct FWeaponProxy;

enum EBackpackViewFilter : uint8
{
	kWeapon,
	kSkill,
	kConsumable,
	kMaterial,
	kAll,
};

/**
 *
 */
UCLASS()
class PROJECT_API UBackpackMenu :
	public UUserWidget_Override
{
	GENERATED_BODY()

public:
	using FOnDragIconDelegate = TCallbackHandleContainer<void(
		bool,
		const TSharedPtr<FBasicProxy>&


		
		)>;

	using FOnSelectedProxy = TCallbackHandleContainer<void(
		const TSharedPtr<FBasicProxy>&


		
		)>;

	virtual void NativeConstruct() override;

	virtual void EnableMenu() ;

	virtual void DisEnableMenu() ;

	bool bIsPlayerMenu = true;

	TSharedPtr<FCharacterProxy> CurrentProxyPtr = nullptr;

	UAllocationSkillsMenu* AllocationSkillsMenuPtr = nullptr;

protected:
	void BindEvent();

private:
	UPROPERTY(meta = (BindWidget))
	UButton* MaterialBtn = nullptr;

	TArray<TSharedPtr<FBasicProxy>> GetProxys() const;

};
