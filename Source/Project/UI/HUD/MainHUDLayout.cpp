#include "MainHUDLayout.h"

#include "Components/Overlay.h"

void UMainHUDLayout::NativeConstruct()
{
	Super::NativeConstruct();

	if (OverlapPtr)
	{
		OverlapPtr->ClearChildren();
	}
}
