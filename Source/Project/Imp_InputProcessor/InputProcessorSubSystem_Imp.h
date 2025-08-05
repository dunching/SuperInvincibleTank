// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <type_traits>

#include "InputProcessorSubSystemBase.h"

#include "InputProcessorSubSystem_Imp.generated.h"

/**
 */
UCLASS(BlueprintType, Blueprintable)
class PROJECT_API UInputProcessorSubSystem_Imp : public UInputProcessorSubSystemBase
{
	GENERATED_BODY()

public:
	static UInputProcessorSubSystem_Imp* GetInstance();

private:
};
