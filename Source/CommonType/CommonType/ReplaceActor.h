// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Pawn.h"

#include "ReplaceActor.generated.h"

class UPlayerComponent;
class USphereComponent;
class UFloatingPawnMovement;
class USpringArmComponent;
class UCameraComponent;
class AViewerPawn;

/**
 * 雷达扫描效果
 */
UCLASS()
class COMMONTYPE_API AReplaceActor :
	public AActor
{
	GENERATED_BODY()

public:

	AReplaceActor(
		const FObjectInitializer& ObjectInitializer
		);

};
