#include "InventoryComponent.h"

#include <GameFramework/PlayerState.h>

#include "Net/UnrealNetwork.h"

#include "GameplayTagsLibrary.h"
#include "ModifyItemProxyStrategy.h"

void UInventoryComponent::InitializeComponent()
{
	Super::InitializeComponent();
	{
		auto ModifyItemProxyStrategySPtr = MakeShared<FModifyItemProxyStrategy_Coin>();
		ModifyItemProxyStrategiesMap.Add(
		                                 ModifyItemProxyStrategySPtr->GetCanOperationType(),
		                                 ModifyItemProxyStrategySPtr
		                                );
	}
	{
		auto ModifyItemProxyStrategySPtr = MakeShared<FModifyItemProxyStrategy_PlatformExtension>();
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

AGroupManagger* UInventoryComponent::GetGroupManagger() const
{
	return nullptr;
}
