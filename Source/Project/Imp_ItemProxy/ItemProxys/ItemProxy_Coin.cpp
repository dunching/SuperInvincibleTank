
#include "ItemProxy_Coin.h"

FItemProxy_Coin::FItemProxy_Coin()
{

}

bool FItemProxy_Coin::NetSerialize(FArchive& Ar, class UPackageMap* Map, bool& bOutSuccess)
{
	Super::NetSerialize(Ar, Map, bOutSuccess);
	NetSerialize_Allocationble(Ar, Map, bOutSuccess);
	NetSerialize_Unique(Ar, Map, bOutSuccess);

	return true;
}

void FItemProxy_Coin::InitialProxy(
	const FGameplayTag& InProxyType
	)
{
	Super::InitialProxy(InProxyType);
	
	ProxyPtr = this;
}

void FItemProxy_Coin::UpdateByRemote(
	const TSharedPtr<FItemProxy_Coin>& RemoteSPtr
	)
{
	Super::UpdateByRemote(RemoteSPtr);
	
	ProxyPtr = this;
	UpdateByRemote_Allocationble(RemoteSPtr);
	
	UpdateByRemote_Unique(RemoteSPtr);
}

void FItemProxy_Coin::ModifyNum(
	int32 Value
	)
{
	IProxy_Unique::ModifyNum(Value);

	UpdateData();
}

bool FItemProxy_Coin::IsUnique() const
{
	return true;
}
