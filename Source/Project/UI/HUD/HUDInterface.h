// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "UserWidget_Override.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Interface.h"

#include "HUDInterface.generated.h"

UINTERFACE(MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UHUDInterface : public UInterface
{
	GENERATED_BODY()
};

class PROJECT_API IHUDInterface
{
	GENERATED_BODY()

public:

	virtual void ResetUIByData() = 0;

protected:

private:

};
