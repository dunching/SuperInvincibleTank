
#include "BackpackIconWrapper.h"

#include <Kismet/GameplayStatics.h>
#include "Containers/UnrealString.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Components/SizeBox.h"
#include "Components/Border.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Engine/Texture2D.h"
#include "Components/CanvasPanel.h"

#include "AssetRefMap.h"
#include "ItemProxyDragDropOperation.h"
#include "ItemProxyDragDropOperationWidget.h"
#include "ItemProxy_Minimal.h"
#include "GameplayTagsLibrary.h"

namespace BackpackIconWrapper
{
	const FName Border = TEXT("Border");
}

UBackpackIconWrapper::UBackpackIconWrapper(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{

}

void UBackpackIconWrapper::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);

	InvokeReset(Cast<ThisClass>(ListItemObject));
}

void UBackpackIconWrapper::InvokeReset(UUserWidget* BaseWidgetPtr)
{
	if (BaseWidgetPtr)
	{
		auto NewPtr = Cast<ThisClass>(BaseWidgetPtr);
		if (NewPtr)
		{
			AllocationSkillsMenuPtr = NewPtr->AllocationSkillsMenuPtr;
			ResetToolUIByData(NewPtr->TargetBasicProxyPtr);
		}
	}
}

void UBackpackIconWrapper::ResetToolUIByData(const TSharedPtr<FBasicProxy>& BasicProxyPtr)
{
	if (BasicProxyPtr)
	{
		TargetBasicProxyPtr = BasicProxyPtr;
	}
}

void UBackpackIconWrapper::EnableIcon(bool bIsEnable)
{

}
