#pragma once

#include <functional>

#include "CoreMinimal.h"

#include "InputProcessor.h"
#include "GenerateTypes.h"
#include "PlatformCharacter.h"

class ATrackVehicleBase;
class AStartignPawn;
class AHorseCharacter;
class ABuildingBase;
class APlatformCharacter;

namespace Processors
{
	/**
	 * 配置界面
	 */
	class PROJECT_API FAllocationProcessor : public FInputProcessor
	{
	private:
		GENERATIONCLASSINFO(FAllocationProcessor, FInputProcessor);

	public:
		using FOwnerPawnType = AStartignPawn;

		FAllocationProcessor();

		virtual void EnterAction() override;

		virtual bool InputKey(
			const FInputKeyEventArgs& EventArgs
		) override;

		void SelectedPlatformType(const FGameplayTag&PlatformTypeTag);

		FGameplayTag CurrentPlatformTypeTag;
		
		TObjectPtr<APlatformCharacter>CurrentPlatformCharacterPtr = nullptr;
	};
}
