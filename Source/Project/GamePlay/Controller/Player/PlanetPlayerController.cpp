#include "PlanetPlayerController.h"

#include "InputProcessorSubSystem_Imp.h"
#include "PlayerGameplayTasks.h"
#include "StartingProcessor.h"
#include "AllocationPawn.h"
#include "GroupManagger.h"
#include "InventoryComponentBase.h"
#include "LogWriter.h"
#include "GroupManaggerImp.h"
#include "PixelStreamingInputComponent.h"

APlanetPlayerController::APlanetPlayerController(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{
	GameplayTasksComponentPtr = CreateDefaultSubobject<UPlayerControllerGameplayTasksComponent>(
		UPlayerControllerGameplayTasksComponent::ComponentName
	);
}

void APlanetPlayerController::BeginPlay()
{
	Super::BeginPlay();

#if UE_EDITOR || UE_CLIENT
	if (GetLocalRole() == ROLE_AutonomousProxy)
	{
		UInputProcessorSubSystem_Imp::GetInstance()->SwitchToProcessor<Processors::FStartingProcessor>(
			[this](
			auto NewProcessor
		)
			{
			}
		);
	}
#endif
}

void APlanetPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	bool bIsNewPawn = (InPawn != GetPawn());

	if (bIsNewPawn)
	{
	}
}

void APlanetPlayerController::OnRep_Pawn()
{
	Super::OnRep_Pawn();
}

void APlanetPlayerController::GetLifetimeReplicatedProps(
	TArray<FLifetimeProperty>& OutLifetimeProps
	) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

void APlanetPlayerController::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	InitialGroupManagger();
}

AGroupManagger* APlanetPlayerController::GetGroupManagger() const
{
	return GroupManaggerPtr;
}

void APlanetPlayerController::InitialGroupManagger()
{
#if UE_EDITOR || UE_SERVER
	if (GetNetMode() == NM_DedicatedServer)
	{
		FActorSpawnParameters SpawnParameters;

		SpawnParameters.Owner = this;
		SpawnParameters.CustomPreSpawnInitalization = [](
			AActor* ActorPtr
			)
		{
			PRINTINVOKEINFO();
			auto GroupManaggerPtr = Cast<AGroupManagger>(ActorPtr);
			if (GroupManaggerPtr)
			{
				GroupManaggerPtr->GroupID = FGuid::NewGuid();
			}
		};

		GroupManaggerPtr = GetWorld()->SpawnActor<AGroupManaggerImp>(
																		 AGroupManaggerImp::StaticClass(),
																		 SpawnParameters
																		);
	}
#endif
}

void APlanetPlayerController::OnRep_GroupManagger()
{
}

void APlanetPlayerController::AddProxy_Server_Implementation(
	const FGameplayTag& ProxyType,
	int32 Num
	)
{
	auto InventoryComponentPtr = GetGroupManagger()->GetInventoryComponentBase();
	if (InventoryComponentPtr)
	{
		InventoryComponentPtr->AddProxyNum(
										   ProxyType,
										   Num
										  );
	}
}

void APlanetPlayerController::Possess_Server_Implementation(
	APawn* InPawn
	)
{
	Possess(InPawn);
}
