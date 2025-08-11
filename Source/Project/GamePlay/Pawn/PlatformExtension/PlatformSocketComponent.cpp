#include "PlatformSocketComponent.h"

#include "Components/BillboardComponent.h"
#include "Components/BoxComponent.h"

UPlatformSocketComponent::UPlatformSocketComponent(
	const FObjectInitializer& ObjectInitializer
	):
	 Super(ObjectInitializer)
{
#if WITH_EDITORONLY_DATA
	BillboardComponent = CreateEditorOnlyDefaultSubobject<UBillboardComponent>(TEXT("Arrow"));
	if (BillboardComponent)
	{
		BillboardComponent->SetupAttachment(this);
	}
#endif // WITH_EDITORONLY_DATA
}
