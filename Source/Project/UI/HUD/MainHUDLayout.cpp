#include "MainHUDLayout.h"

#include "LayoutWidgetBase.h"
#include "Components/Overlay.h"
#include "Components/WidgetSwitcher.h"

void UMainHUDLayout::NativeConstruct()
{
	Super::NativeConstruct();

	if (OverlapPtr)
	{
		OverlapPtr->ClearChildren();
	}

	if (WidgetSwitcherPtr)
	{
		WidgetSwitcherPtr->SetActiveWidgetIndex(0);
	}
}

void UMainHUDLayout::SwitchLayout(
	const FGameplayTag& LayoutTag
	) const
{
	if (WidgetSwitcherPtr)
	{
		auto ChildrensAry = WidgetSwitcherPtr->GetAllChildren();
		for (auto Child : ChildrensAry)
		{
			auto LayoutBasePtr = Cast<ULayoutWidgetBase>(Child);
			if (LayoutBasePtr && LayoutBasePtr->LayoutTag == LayoutTag)
			{
				WidgetSwitcherPtr->SetActiveWidget(LayoutBasePtr);
				break;
			}
		}
	}
}
