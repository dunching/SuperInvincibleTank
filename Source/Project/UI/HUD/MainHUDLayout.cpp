#include "MainHUDLayout.h"

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
