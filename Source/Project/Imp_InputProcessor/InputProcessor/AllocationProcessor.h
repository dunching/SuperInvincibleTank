#pragma once

#include <functional>

#include "CoreMinimal.h"

#include "InputProcessor.h"
#include "GenerateTypes.h"

class ATrackVehicleBase;
class ATourPawn;
class AHorseCharacter;
class ABuildingBase;

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
		using FOwnerPawnType = ATourPawn;

		FAllocationProcessor();

		virtual void EnterAction() override;

		virtual bool InputKey(
			const FInputKeyEventArgs& EventArgs
		) override;
	};
}
