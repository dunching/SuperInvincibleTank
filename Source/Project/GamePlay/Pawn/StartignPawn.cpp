#include "StartignPawn.h"

#include "GameOptions.h"
#include "Components/SphereComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

#include "PlayerComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

AStartignPawn::AStartignPawn(const FObjectInitializer& ObjectInitializer):
	Super(
		ObjectInitializer)
{
	PlayerComponentPtr = CreateDefaultSubobject<UPlayerComponent>(UPlayerComponent::ComponentName);

	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
	CollisionComponent->InitSphereRadius(35.0f);
	CollisionComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);

	CollisionComponent->CanCharacterStepUpOn = ECB_No;
	CollisionComponent->SetShouldUpdatePhysicsVolume(true);
	CollisionComponent->SetCanEverAffectNavigation(false);
	CollisionComponent->bDynamicObstacle = true;

	RootComponent = CollisionComponent;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);

	MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MovementComponent"));
	MovementComponent->UpdatedComponent = CollisionComponent;
}

void AStartignPawn::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	PlayerComponentPtr->PossessedBy(Cast<APlayerController>(NewController));
}

void AStartignPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerComponentPtr->SetupPlayerInputComponent(PlayerInputComponent);
}

void AStartignPawn::LerpToSeat(const FTransform& Transform, float SpringArmLen)
{
	const auto Rot = Transform.GetRotation().Rotator();
	
	auto NewRot = Rot;
	
	SetActorLocation(Transform.GetLocation());

	SpringArmComponent->TargetArmLength = SpringArmLen;

	GetController()->SetControlRotation(Rot);
}

void AStartignPawn::UpdateControlParam(
	const FControlParam& ControlParam
	)
{
	MovementComponent->MaxSpeed = ControlParam.MaxMoveSpeed;
	MovementComponent->Acceleration = ControlParam.Acceleration;
	MovementComponent->Deceleration = ControlParam.Deceleration;
}
