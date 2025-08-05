
#include "StartingLayout.h"

#include "Components/Button.h"

#include "AllocationProcessor.h"
#include "InputProcessorSubSystem_Imp.h"
#include "StartingProcessor.h"

void UStartingLayout::NativeConstruct()
{
	Super::NativeConstruct();

 	ButtonPtr->OnClicked.AddDynamic(this, &ThisClass::OnClicked);
}

void UStartingLayout::OnClicked()
{
	UInputProcessorSubSystem_Imp::GetInstance()->SwitchToProcessor<Processors::FAllocationProcessor>(
		[this](
		auto NewProcessor
	)
		{
		}
	);
}
