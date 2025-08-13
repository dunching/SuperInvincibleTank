// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include <Subsystems/GameInstanceSubsystem.h>
#include <Subsystems/EngineSubsystem.h>

#include "GameplayTagsLibrary.generated.h"

UCLASS()
class GAMEPLAYTAGSLIBRARY_API UGameplayTagsLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	static FGameplayTag Proxy_Coin;

	static FGameplayTag Proxy_Coin_Regular;

	
	static FGameplayTag Proxy_Platform_InLand;

	static FGameplayTag Proxy_Platform_InLand_3X5;

	static FGameplayTag Proxy_Platform_InLand_6X10;

	static FGameplayTag Proxy_Extension;

	static FGameplayTag Proxy_Extension_Weapon;

	
	static FGameplayTag UI_Allocation;

};