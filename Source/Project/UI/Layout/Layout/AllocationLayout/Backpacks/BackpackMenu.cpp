#include "BackpackMenu.h"

#include "Components/GridPanel.h"

#include "UICommon.h"
#include "ModifyItemProxyStrategy.h"

struct FBackpackMenu : public TStructVariable<FBackpackMenu>
{
	const FName BackpackTile = TEXT("BackpackTile");

	const FName WeaponBtn = TEXT("WeaponBtn");

	const FName SkillBtn = TEXT("SkillBtn");

	const FName ConsumableBtn = TEXT("ConsumableBtn");

	const FName ShowAllBtn = TEXT("ShowAllBtn");

	const FName CoinList = TEXT("CoinList");
};

void UBackpackMenu::NativeConstruct()
{
	Super::NativeConstruct();

	BindEvent();
}

void UBackpackMenu::EnableMenu()
{
}

void UBackpackMenu::DisEnableMenu()
{
}

TArray<TSharedPtr<FBasicProxy>> UBackpackMenu::GetProxys() const
{
	TArray<TSharedPtr<FBasicProxy>> Result;
	return Result;
}

void UBackpackMenu::BindEvent()
{
}
