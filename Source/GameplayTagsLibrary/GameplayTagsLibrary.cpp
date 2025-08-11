#include "GameplayTagsLibrary.h"

#include <Subsystems/SubsystemBlueprintLibrary.h>

FGameplayTag UGameplayTagsLibrary::Proxy_Coin =
	FGameplayTag::RequestGameplayTag(FName(TEXT("Proxy.Coin")));

FGameplayTag UGameplayTagsLibrary::Proxy_Coin_Regular =
	FGameplayTag::RequestGameplayTag(FName(TEXT("Proxy.Coin.Regular")));


FGameplayTag UGameplayTagsLibrary::UI_Allocation =
	FGameplayTag::RequestGameplayTag(FName(TEXT("UI.Allocation")));

FGameplayTag UGameplayTagsLibrary::Platform_InLand =
	FGameplayTag::RequestGameplayTag(FName(TEXT("Platform.InLand")));

FGameplayTag UGameplayTagsLibrary::Platform_InLand_3X5 =
	FGameplayTag::RequestGameplayTag(FName(TEXT("Platform.InLand.3X5")));

FGameplayTag UGameplayTagsLibrary::Platform_InLand_6X10 =
	FGameplayTag::RequestGameplayTag(FName(TEXT("Platform.InLand.6X10")));
