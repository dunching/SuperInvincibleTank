#include "Planet_ItemProxy.h"

#include "InventoryComponent.h"
#include "ItemProxy.h"

inline void FProject_BasicProxy::SetInventoryComponent(
	const TObjectPtr<UInventoryComponent>& NewInventoryComponentPtr
	)
{
	SetInventoryComponentBase(NewInventoryComponentPtr);
}

TObjectPtr<UInventoryComponent> FProject_BasicProxy::GetInventoryComponent() const
{
	return Cast<UInventoryComponent>(GetInventoryComponentBase());
}
