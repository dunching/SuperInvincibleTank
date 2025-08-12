
#include "PAD_ItemProxyCollection.h"

#include <Kismet/GameplayStatics.h>

#include "GameplayTagsManager.h"
#include "Tools.h"

const UPAD_ItemProxyCollection* UPAD_ItemProxyCollection::GetInstance()
{
	auto WorldSetting = Cast<IGetItemProxyCollectionInterface>(GetWorldImp()->GetWorldSettings());
	return WorldSetting->GetItemProxyCollection();
}

const FProxyDescriptionHelper UPAD_ItemProxyCollection::GetTableRowProxy(
	FGameplayTag ProxyType
	) const
{
	if (ProxyDescriptionMap.Contains(ProxyType))
	{
		return ProxyDescriptionMap[ProxyType];
	}

	return FProxyDescriptionHelper();
}
