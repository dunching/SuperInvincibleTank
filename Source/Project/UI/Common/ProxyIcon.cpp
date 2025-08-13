#include "ProxyIcon.h"

#include "Components/Image.h"
#include "Engine/AssetManager.h"
#include "Blueprint/SlateBlueprintLibrary.h"
#include "Kismet/GameplayStatics.h"

#include "DataTableCollection.h"
#include "ItemDecription.h"
#include "ItemProxy_Description.h"
#include "TemplateHelper.h"
#include "UICommon.h"

struct FProxyIcon : public TStructVariable<FProxyIcon>
{
	const FName Content = TEXT("Content");

	const FName Icon = TEXT("Icon");
};

inline void UProxyIcon::ResetToolUIByData(
	const TSharedPtr<FBasicProxy>& InBasicProxyPtr
	)
{
	if (InBasicProxyPtr)
	{
		ProxySPtr = InBasicProxyPtr;
	}
	else
	{
		ProxySPtr = nullptr;
	}

	SetItemType();
}

void UProxyIcon::ResetToolUIByData(
	const FGameplayTag& InProxyType
	)
{
	ProxyType = InProxyType;

	SetItemType();
}

void UProxyIcon::NativeOnMouseEnter(
	const FGeometry& InGeometry,
	const FPointerEvent& InMouseEvent
	)
{
	Super::NativeOnMouseEnter(InGeometry, InMouseEvent);

	if (bIsDisplayInfo)
	{
		if (ProxySPtr)
		{
		}
		else if (ProxyType.IsValid())
		{
		}
	}
}

void UProxyIcon::NativeOnMouseLeave(
	const FPointerEvent& InMouseEvent
	)
{

	Super::NativeOnMouseLeave(InMouseEvent);
}

void UProxyIcon::SetItemType()
{
	auto ImagePtr = Cast<UImage>(GetWidgetFromName(FProxyIcon::Get().Icon));
	if (ImagePtr)
	{
		if (ProxySPtr)
		{
		}
		else if (ProxyType.IsValid())
		{
		}
		else
		{
			ImagePtr->SetVisibility(ESlateVisibility::Hidden);
		}
	}
}
