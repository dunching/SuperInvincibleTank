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
	 * 游戏模式
	 */
	class PROJECT_API FPlayingProcessor : public FInputProcessor
	{
	private:
		GENERATIONCLASSINFO(FPlayingProcessor, FInputProcessor);

	public:
		using FOwnerPawnType = AStartignPawn;

		FPlayingProcessor();

		virtual void EnterAction() override;

		virtual bool InputKey(
			const FInputKeyEventArgs& EventArgs
		) override;
	};
}
