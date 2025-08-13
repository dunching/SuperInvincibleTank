// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "ItemProxy_Minimal.h"
#include "TeamConfigure.h"
#include "TeamMatesHelperComponent.h"

#include "TeamMatesHelperImpComponent.generated.h"

class AHumanCharacter;
class ACharacterBase;
class IPlanetControllerInterface;
class AGroupManagger;
struct FSkillProxy;
struct FActiveSkillProxy;
struct FConsumableProxy;
struct FCharacterProxy;
class UPlanetAbilitySystemComponent;
class UProxySycHelperComponent;
struct FSceneProxyContainer;

/*
 *	“小队”信息
 *
 *	共享GroupManagger数据的Character会记录在此
 *	玩家的队伍配置会记录在此
 */
UCLASS(BlueprintType, Blueprintable)
class PROJECT_API UTeamMatesHelperImpComponent : public UTeamMatesHelperComponent
{
	GENERATED_BODY()

public:
};
