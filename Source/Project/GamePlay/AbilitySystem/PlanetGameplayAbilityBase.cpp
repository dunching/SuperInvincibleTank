#include "PlanetGameplayAbilityBase.h"

#include "AbilitySystemComponent.h"
#include "AssetRefMap.h"
#include "GameplayTagsLibrary.h"

UGameplayEffect* UPlanetGameplayAbilityBase::GetCooldownGameplayEffect() const
{
	return UAssetRefMap::GetInstance()->DurationGEClass.GetDefaultObject();
}

UGameplayEffect* UPlanetGameplayAbilityBase::GetCostGameplayEffect() const
{
	return UAssetRefMap::GetInstance()->OnceGEClass.GetDefaultObject();
}

bool UPlanetGameplayAbilityBase::CheckCooldown(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	FGameplayTagContainer* OptionalRelevantTags
	) const
{
	if (!ensure(ActorInfo))
	{
		return true;
	}

	return true;
}

const FGameplayTagContainer* UPlanetGameplayAbilityBase::GetCooldownTags() const
{
	return nullptr;
}

void UPlanetGameplayAbilityBase::ApplyCost(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo
	) const
{
	ApplyCostImp(Handle, ActorInfo, ActivationInfo, FGameplayTag::EmptyTag, GetCostMap());
}

bool UPlanetGameplayAbilityBase::CheckCost(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	FGameplayTagContainer* OptionalRelevantTags
	) const
{
	return true;
}

void UPlanetGameplayAbilityBase::ApplyCostImp(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayTag& CDTag,
	const TMap<FGameplayTag, int32>& CostMap
	) const
{
}

TArray<FActiveGameplayEffectHandle> UPlanetGameplayAbilityBase::MyApplyGameplayEffectSpecToTarget(
	const FGameplayAbilitySpecHandle AbilityHandle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	FGameplayEffectSpecHandle SpecHandle,
	const FGameplayAbilityTargetDataHandle& TargetData
	) const
{
	return ApplyGameplayEffectSpecToTarget(AbilityHandle, ActorInfo, ActivationInfo, SpecHandle, TargetData);
}

void UPlanetGameplayAbilityBase::ApplyCDImp(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayTag& CDTag,
	int32 Cooldown
	) const
{
}

TMap<FGameplayTag, int32> UPlanetGameplayAbilityBase::GetCostMap() const
{
	return {};
}
