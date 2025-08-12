#include "GameplayTagsLibrary.h"

#include <Subsystems/SubsystemBlueprintLibrary.h>

FGameplayTag UGameplayTagsLibrary::Proxy_Coin =
	FGameplayTag::RequestGameplayTag(FName(TEXT("Proxy.Coin")));

FGameplayTag UGameplayTagsLibrary::Proxy_Coin_Regular =
	FGameplayTag::RequestGameplayTag(FName(TEXT("Proxy.Coin.Regular")));


FGameplayTag UGameplayTagsLibrary::Proxy_Platform_InLand =
	FGameplayTag::RequestGameplayTag(FName(TEXT("Proxy.Platform.InLand")));

FGameplayTag UGameplayTagsLibrary::Proxy_Platform_InLand_3X5 =
	FGameplayTag::RequestGameplayTag(FName(TEXT("Proxy.Platform.InLand.3X5")));

FGameplayTag UGameplayTagsLibrary::Proxy_Platform_InLand_6X10 =
	FGameplayTag::RequestGameplayTag(FName(TEXT("Proxy.Platform.InLand.6X10")));

FGameplayTag UGameplayTagsLibrary::Proxy_Extension_Weapon =
	FGameplayTag::RequestGameplayTag(FName(TEXT("Proxy.Extension.Weapon")));


FGameplayTag UGameplayTagsLibrary::UI_Allocation =
	FGameplayTag::RequestGameplayTag(FName(TEXT("UI.Allocation")));
