// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "PlatformCharacter.h"
#include "SceneActorInteractionComponent.h"

#include "HumanCharacter_Player.generated.h"

class UPlayerComponent;
class AHumanCharacter_AI;
class USpringArmComponent;
class UCameraComponent;
class UPlanetGameplayCameraComponent;
class UGameplayCameraComponent;

class UInteractionList;
class AHumanCharacter_Player;

UCLASS()
class PROJECT_API AHumanCharacter_Player : public APlatformCharacter
{
	GENERATED_BODY()

public:
};
