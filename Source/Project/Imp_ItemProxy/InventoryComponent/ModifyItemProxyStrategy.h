// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <set>

#include "CoreMinimal.h"

#include "UObject/ObjectMacros.h"
#include "UObject/Interface.h"

#include "ModifyItemProxyStrategyInterface.h"
#include "TemplateHelper.h"
#include "ItemProxy_Minimal.h"

struct FCoinProxy;
struct FConsumableProxy;
struct FCharacterProxy;
struct FWeaponProxy;
struct FSkillProxy;
struct FPassiveSkillProxy;
struct FActiveSkillProxy;
struct FWeaponSkillProxy;

struct PROJECT_API FModifyItemProxyStrategy_Coin : public FModifyItemProxyStrategyBase<FCoinProxy>
{
	using FItemProxyType = FCoinProxy;

	using FOnCoinProxyChanged = TCallbackHandleContainer<void(
		const TSharedPtr<
			FItemProxyType>&,
		EProxyModifyType,
		int32
		)>;

	virtual FGameplayTag GetCanOperationType() const override;

	virtual TArray<TSharedPtr<FBasicProxy>> FindByType(
		const FGameplayTag& ProxyType,
		const TObjectPtr<const UInventoryComponentBase>& InventoryComponentPtr
		) const override;

	virtual TArray<TSharedPtr<FBasicProxy>> Add(
		const TObjectPtr<UInventoryComponentBase>& InventoryComponentPtr,
		const FGameplayTag& InProxyType,
		int32 Num
		) override;

	virtual TSharedPtr<FBasicProxy> AddByRemote(
		const TObjectPtr<UInventoryComponentBase>& InventoryComponentPtr,
		const TSharedPtr<FBasicProxy>& RemoteProxySPtr
		) override;

	virtual TSharedPtr<FBasicProxy> UpdateByRemote(
		const TObjectPtr<UInventoryComponentBase>& InventoryComponentPtr,
		const TSharedPtr<FBasicProxy>& LocalProxySPtr,
		const TSharedPtr<FBasicProxy>& RemoteProxySPtr
		) override;

	virtual void RemoveByRemote(
		const TObjectPtr<UInventoryComponentBase>& InventoryComponentPtr,
		const TSharedPtr<FBasicProxy>& RemoteProxySPtr
		) override;

	FOnCoinProxyChanged OnCoinProxyChanged;

	TMap<FGameplayTag, TArray<TSharedPtr<FItemProxyType>>> ProxyTypeMap;
};
