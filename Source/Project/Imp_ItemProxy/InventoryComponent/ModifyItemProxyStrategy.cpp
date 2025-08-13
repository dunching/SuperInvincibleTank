#include "ModifyItemProxyStrategy.h"

#include "GameplayTagsLibrary.h"
#include "InventoryComponentBase.h"
#include "ItemProxy_Coin.h"

FGameplayTag FModifyItemProxyStrategy_Coin::GetCanOperationType() const
{
	return UGameplayTagsLibrary::Proxy_Coin;
}

TArray<TSharedPtr<FBasicProxy>> FModifyItemProxyStrategy_Coin::FindByType(
	const FGameplayTag& ProxyType,
	const TObjectPtr<const UInventoryComponentBase>& InventoryComponentPtr
	) const
{
	TArray<TSharedPtr<FBasicProxy>> Result;
	if (ProxyTypeMap.Contains(ProxyType))
	{
		Result.Append(ProxyTypeMap[ProxyType]);
	}

	return Result;
}

TArray<TSharedPtr<FBasicProxy>> FModifyItemProxyStrategy_Coin::Add(
	const TObjectPtr<UInventoryComponentBase>& InventoryComponentPtr,
	const FGameplayTag& InProxyType,
	int32 Num
	)
{
	if (auto ProxySPtr = InventoryComponentPtr->FindProxyType(InProxyType))
	{
		auto NewResultSPtr = DynamicCastSharedPtr<FItemProxyType>(ProxySPtr);

		NewResultSPtr->ModifyNum(Num);

		InventoryComponentPtr->UpdateInContainer(NewResultSPtr);

		OnCoinProxyChanged.ExcuteCallback(NewResultSPtr, EProxyModifyType::kAdd, Num);

		return {NewResultSPtr};
	}
	else
	{
		auto NewResultSPtr = MakeShared<FItemProxyType>();

		NewResultSPtr->SetInventoryComponentBase(InventoryComponentPtr);
		NewResultSPtr->InitialProxy(InProxyType);

		NewResultSPtr->ModifyNum(Num);

		InventoryComponentPtr->AddToContainer(NewResultSPtr);

		ProxyTypeMap.Add(InProxyType, {NewResultSPtr});

		OnCoinProxyChanged.ExcuteCallback(NewResultSPtr, EProxyModifyType::kPropertyChange, Num);

		return {NewResultSPtr};
	}
}

TSharedPtr<FBasicProxy> FModifyItemProxyStrategy_Coin::AddByRemote(
	const TObjectPtr<UInventoryComponentBase>& InventoryComponentPtr,
	const TSharedPtr<FBasicProxy>& RemoteProxySPtr
	)
{
	auto NewResultSPtr = DynamicCastSharedPtr<FItemProxyType>(
	                                                          FModifyItemProxyStrategyBase<FItemProxyType>::AddByRemote(
		                                                           InventoryComponentPtr,
		                                                           RemoteProxySPtr
		                                                          )
	                                                         );

	ProxyTypeMap.Add(NewResultSPtr->GetProxyType(), {NewResultSPtr});

	OnCoinProxyChanged.ExcuteCallback(NewResultSPtr, EProxyModifyType::kPropertyChange, NewResultSPtr->GetNum());

	return NewResultSPtr;
}

TSharedPtr<FBasicProxy> FModifyItemProxyStrategy_Coin::UpdateByRemote(
	const TObjectPtr<UInventoryComponentBase>& InventoryComponentPtr,
	const TSharedPtr<FBasicProxy>& LocalProxySPtr,
	const TSharedPtr<FBasicProxy>& RemoteProxySPtr
	)
{
	auto NewResultSPtr = DynamicCastSharedPtr<FItemProxyType>(
	                                                          FModifyItemProxyStrategyBase<
		                                                          FItemProxyType>::UpdateByRemote(
		                                                           InventoryComponentPtr,
		                                                           LocalProxySPtr,
		                                                           RemoteProxySPtr
		                                                          )
	                                                         );

	OnCoinProxyChanged.ExcuteCallback(NewResultSPtr, EProxyModifyType::kPropertyChange, NewResultSPtr->GetNum());

	return NewResultSPtr;
}

void FModifyItemProxyStrategy_Coin::RemoveByRemote(
	const TObjectPtr<UInventoryComponentBase>& InventoryComponentPtr,
	const TSharedPtr<FBasicProxy>& RemoteProxySPtr
	)
{
	FModifyItemProxyStrategyBase<
		FItemProxyType>::RemoveByRemote(
		                                InventoryComponentPtr,
		                                RemoteProxySPtr
		                               );

	ProxyTypeMap.Remove(RemoteProxySPtr->GetProxyType());

	OnCoinProxyChanged.ExcuteCallback(
	                                  DynamicCastSharedPtr<FItemProxyType>(RemoteProxySPtr),
	                                  EProxyModifyType::kRemove,
	                                  0
	                                 );
}


FGameplayTag FModifyItemProxyStrategy_PlatformExtension::GetCanOperationType() const
{
	return UGameplayTagsLibrary::Proxy_Extension;
}

TArray<TSharedPtr<FBasicProxy>> FModifyItemProxyStrategy_PlatformExtension::FindByType(
	const FGameplayTag& ProxyType,
	const TObjectPtr<const UInventoryComponentBase>& InventoryComponentPtr
	) const
{
	TArray<TSharedPtr<FBasicProxy>> Result;
	if (ProxyTypeMap.Contains(ProxyType))
	{
		Result.Append(ProxyTypeMap[ProxyType]);
	}

	return Result;
}

TArray<TSharedPtr<FBasicProxy>> FModifyItemProxyStrategy_PlatformExtension::Add(
	const TObjectPtr<UInventoryComponentBase>& InventoryComponentPtr,
	const FGameplayTag& InProxyType,
	int32 Num
	)
{
	auto NewResultSPtr = MakeShared<FItemProxyType>();

	NewResultSPtr->SetInventoryComponentBase(InventoryComponentPtr);
	NewResultSPtr->InitialProxy(InProxyType);

	InventoryComponentPtr->AddToContainer(NewResultSPtr);

	OnProxyChanged(NewResultSPtr, EProxyModifyType::kAdd);

	return {NewResultSPtr};
}

TSharedPtr<FBasicProxy> FModifyItemProxyStrategy_PlatformExtension::AddByRemote(
	const TObjectPtr<UInventoryComponentBase>& InventoryComponentPtr,
	const TSharedPtr<FBasicProxy>& InRemoteProxySPtr
	)
{
	auto NewResultSPtr = DynamicCastSharedPtr<FItemProxyType>(
															  FModifyItemProxyStrategyBase<FItemProxyType>::AddByRemote(
																   InventoryComponentPtr,
																   InRemoteProxySPtr
																  )
															 );

	OnProxyChanged.ExcuteCallback(NewResultSPtr, EProxyModifyType::kPropertyChange);

	return NewResultSPtr;
}
