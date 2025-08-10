#pragma once

#include <functional>

#include "CoreMinimal.h"

#include "InputProcessor.h"
#include "GenerateTypes.h"

class ATrackVehicleBase;
class AStartignPawn;
class AHorseCharacter;
class ABuildingBase;

namespace Processors
{
	/**
	 * 开始界面
	 */
	class PROJECT_API FStartingProcessor : public FInputProcessor
	{
	private:
		GENERATIONCLASSINFO(FStartingProcessor, FInputProcessor);

	public:
		using FOwnerPawnType = AStartignPawn;

		FStartingProcessor();

		virtual void EnterAction() override;

		virtual bool InputKey(
			const FInputKeyEventArgs& EventArgs
		) override;
	};
}
