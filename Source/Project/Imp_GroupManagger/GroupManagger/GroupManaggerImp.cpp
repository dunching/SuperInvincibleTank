#include "GroupManaggerImp.h"

#include "TeamMatesHelperComponent.h"

#include "InventoryComponent.h"
#include "PlanetPlayerController.h"
#include "UGSAbilitySystemComponent.h"

AGroupManaggerImp::AGroupManaggerImp(
	const FObjectInitializer& ObjectInitializer
	):
	 Super(
	       ObjectInitializer.
	       SetDefaultSubobjectClass<UTeamMatesHelperComponent>(
	                                                           UTeamMatesHelperComponent::ComponentName
	                                                          )
	       .
	       SetDefaultSubobjectClass<UInventoryComponent>(
	                                                     UInventoryComponent::ComponentName
	                                                    )
	      )
{
}

void AGroupManaggerImp::BeginPlay()
{
	Super::BeginPlay();
}

void AGroupManaggerImp::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	UWorld* World = GetWorld();
	if ((World->IsGameWorld()))
	{
		//
		GetTeamMatesHelperComponent()->SwitchTeammateOption(ETeammateOption::kInitialize);
	}
}

UPlanetAbilitySystemComponent* AGroupManaggerImp::GetAbilitySystemComponent() const
{
	return AbilitySystemComponentPtr;
}

UTeamMatesHelperComponent* AGroupManaggerImp::GetTeamMatesHelperComponent()
{
	return Cast<UTeamMatesHelperComponent>(TeamMatesHelperComponentPtr);
}

UInventoryComponent* AGroupManaggerImp::GetInventoryComponent()
{
	return Cast<UInventoryComponent>(InventoryComponentPtr);
}
