#include "PlatformItemOption.h"

#include "AllocationProcessor.h"
#include "InputProcessorSubSystem_Imp.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

void UPlatformItemOption::NativePreConstruct()
{
	Super::NativePreConstruct();

	TextPtr->SetText(Text);
}

void UPlatformItemOption::NativeConstruct()
{
	Super::NativeConstruct();

	ButtonPtr->OnClicked.AddDynamic(this, &ThisClass::OnClicked);
}

void UPlatformItemOption::OnClicked()
{
	auto AllocationProcessorSPtr = UInputProcessorSubSystem_Imp::GetInstance()->TryGetCurrentAction<
		Processors::FAllocationProcessor>();
	if (AllocationProcessorSPtr)
	{
		AllocationProcessorSPtr->SelectedPlatformType(PlatformTypeTag);
	}
}
