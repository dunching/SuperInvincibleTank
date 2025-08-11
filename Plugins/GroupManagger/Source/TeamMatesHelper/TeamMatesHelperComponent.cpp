#include "TeamMatesHelperComponent.h"

#include "Net/UnrealNetwork.h"
#include "Kismet/GameplayStatics.h"

#include "LogWriter.h"
#include "TeamConfigure.h"

#ifdef WITH_EDITOR
static TAutoConsoleVariable<int32> GroupMnaggerComponent_KnowCharaterChanged(
                                                                             TEXT(
	                                                                              "GroupMnaggerComponent.KnowCharaterChanged"
	                                                                             ),
                                                                             1,
                                                                             TEXT("")
                                                                             TEXT(" default: 0")
                                                                            );
#endif

UTeamMatesHelperComponent::UTeamMatesHelperComponent(
	const FObjectInitializer& ObjectInitializer
	):
	 Super(ObjectInitializer)
{
	SetIsReplicatedByDefault(true);
}

void UTeamMatesHelperComponent::InitializeComponent()
{
	Super::InitializeComponent();
}

void UTeamMatesHelperComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UTeamMatesHelperComponent::SpwanTeammateCharacter()
{
}

bool UTeamMatesHelperComponent::IsMember(
	const FGuid& CharacterID
	) const
{
	for (auto Iter : MembersIDSet)
	{
		if (Iter == CharacterID)
		{
			return true;
		}
	}

	return false;
}

bool UTeamMatesHelperComponent::TeleportTo(
	const FVector& DestLocation,
	const FRotator& DestRotation,
	bool bIsATest,
	bool bNoCheck
	)
{
	return true;
}

void UTeamMatesHelperComponent::SwitchTeammateOption(
	ETeammateOption InTeammateOption
	)
{
	TeammateOption = InTeammateOption;
}

ETeammateOption UTeamMatesHelperComponent::GetTeammateOption() const
{
	return TeammateOption;
}

FName UTeamMatesHelperComponent::ComponentName = TEXT("TeamMatesHelperComponent");

void UTeamMatesHelperComponent::GetLifetimeReplicatedProps(
	TArray<FLifetimeProperty>& OutLifetimeProps
	) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(ThisClass, TeamConfigure, COND_None);
	DOREPLIFETIME_CONDITION(ThisClass, TeammateOption, COND_None);

	DOREPLIFETIME_CONDITION(ThisClass, MembersIDSet, COND_None);
}

void UTeamMatesHelperComponent::OnRep_MembersIDSet()
{
}

void UTeamMatesHelperComponent::OnRep_TeamConfigure()
{
	TeamHelperChangedDelegateContainer();
	PRINTINVOKEWITHSTR(FString(TEXT("")));
}

void UTeamMatesHelperComponent::OnRep_TeammateOptionChanged()
{
}
