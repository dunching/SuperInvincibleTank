#include "InventoryComponent.h"

#include <GameFramework/PlayerState.h>

#include "Net/UnrealNetwork.h"

#include "GameplayTagsLibrary.h"
#include "ModifyItemProxyStrategy.h"

void UInventoryComponent::InitializeComponent()
{
	Super::InitializeComponent();

	//
	ModifyItemProxyStrategiesMap.Empty();
	{
		auto ModifyItemProxyStrategySPtr = MakeShared<FModifyItemProxyStrategy_Character>();
		ModifyItemProxyStrategiesMap.Add(
		                                 ModifyItemProxyStrategySPtr->GetCanOperationType(),
		                                 ModifyItemProxyStrategySPtr
		                                );
	}
	{
		auto ModifyItemProxyStrategySPtr = MakeShared<FModifyItemProxyStrategy_Weapon>();
		ModifyItemProxyStrategiesMap.Add(
		                                 ModifyItemProxyStrategySPtr->GetCanOperationType(),
		                                 ModifyItemProxyStrategySPtr
		                                );
	}
	{
		auto ModifyItemProxyStrategySPtr = MakeShared<FModifyItemProxyStrategy_WeaponSkill>();
		ModifyItemProxyStrategiesMap.Add(
		                                 ModifyItemProxyStrategySPtr->GetCanOperationType(),
		                                 ModifyItemProxyStrategySPtr
		                                );
	}
	{
		auto ModifyItemProxyStrategySPtr = MakeShared<FModifyItemProxyStrategy_ActiveSkill>();
		ModifyItemProxyStrategiesMap.Add(
		                                 ModifyItemProxyStrategySPtr->GetCanOperationType(),
		                                 ModifyItemProxyStrategySPtr
		                                );
	}
	{
		auto ModifyItemProxyStrategySPtr = MakeShared<FModifyItemProxyStrategy_PassveSkill>();
		ModifyItemProxyStrategiesMap.Add(
		                                 ModifyItemProxyStrategySPtr->GetCanOperationType(),
		                                 ModifyItemProxyStrategySPtr
		                                );
	}
	{
		auto ModifyItemProxyStrategySPtr = MakeShared<FModifyItemProxyStrategy_Coin>();
		ModifyItemProxyStrategiesMap.Add(
		                                 ModifyItemProxyStrategySPtr->GetCanOperationType(),
		                                 ModifyItemProxyStrategySPtr
		                                );
	}
	{
		auto ModifyItemProxyStrategySPtr = MakeShared<FModifyItemProxyStrategy_Consumable>();
		ModifyItemProxyStrategiesMap.Add(
		                                 ModifyItemProxyStrategySPtr->GetCanOperationType(),
		                                 ModifyItemProxyStrategySPtr
		                                );
	}
	{
		auto ModifyItemProxyStrategySPtr = MakeShared<FModifyItemProxyStrategy_MaterialProxy>();
		ModifyItemProxyStrategiesMap.Add(
		                                 ModifyItemProxyStrategySPtr->GetCanOperationType(),
		                                 ModifyItemProxyStrategySPtr
		                                );
	}
}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();


#if UE_EDITOR || UE_SERVER
	if (GetNetMode() == NM_DedicatedServer)
	{
		// 初始化一些需要的Proxy
		AddProxyNum(UGameplayTagsLibrary::Proxy_Coin_Regular, 0);
	}
#endif
}

void UInventoryComponent::OnSelfGroupManaggerReady(
	AGroupManagger* NewGroupSharedInfoPtr
	)
{
}

void UInventoryComponent::OnPlayerGroupManaggerReady(
	AGroupManagger* NewGroupSharedInfoPtr
	)
{
}
