#pragma once

#include <functional>

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "GroupManaggerInterface.h"
#include "InventoryComponentBase.h"
#include "InventoryComponentBase.h"
#include "ItemProxy_Minimal.h"
#include "ItemProxy_Container.h"

#include "InventoryComponent.generated.h"

struct FSceneProxyContainer;
struct FBasicProxy;
struct FCharacterProxy;
struct FProxy_FASI;
struct FCharacterSocket;
struct FSkillProxy;
struct FWeaponProxy;
struct IProxy_Allocationble;
struct FWeaponSkillProxy;
struct IProxy_Allocationble;
class IPlanetControllerInterface;
class ACharacterBase;

/*
 *	持有物品相关
 */
UCLASS(BlueprintType, Blueprintable)
class PROJECT_API UInventoryComponent :
	public UInventoryComponentBase,
	public IGroupManaggerInterface
{
	GENERATED_BODY()

public:
	virtual void InitializeComponent() override;

	virtual void BeginPlay() override;

	virtual AGroupManagger* GetGroupManagger() const override;

};
