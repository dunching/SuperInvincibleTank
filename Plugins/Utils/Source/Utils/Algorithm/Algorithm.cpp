#include "Algorithm.h"

#include "Tools.h"

inline TPair<FTransform, float> UKismetAlgorithm::GetCameraSeat(
	const TSet<AActor*>& Actors,
	const FRotator& Rot,
	float FOV
	)
{
	TPair<FTransform, float> Result;

	FBox Box;
	for (auto Iter : Actors)
	{
		if (Iter)
		{
			Box += Iter->GetComponentsBoundingBox();
		}
	}

	DrawDebugBox(
	             GetWorldImp(),
	             Box.GetCenter(),
	             Box.GetExtent(),
	             FColor::Green,
	             false,
	             10
	            );

	Result.Key.SetLocation(Box.GetCenter());
	Result.Key.SetRotation(Rot.Quaternion());

	const auto Radians = FMath::DegreesToRadians(45.0f);
	const auto Value = FMath::Cos(Radians);
	Result.Value = Box.GetSize().Length() / 2 / Value;

	return Result;
}

FBox UKismetAlgorithm::GetActorBox(
	const TSet<AActor*>& Actors
	)
{
	FBox Box;
	for (auto Iter : Actors)
	{
		if (Iter)
		{
			Box += Iter->GetComponentsBoundingBox();
		}
	}
	
	DrawDebugBox(
				 GetWorldImp(),
				 Box.GetCenter(),
				 Box.GetExtent(),
				 FColor::Green,
				 false,
				 10
				);

	return Box;
}
