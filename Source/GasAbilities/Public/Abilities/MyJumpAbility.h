// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "MyJumpAbility.generated.h"

/**
 * UMyJumpAbility is a basic Gameplay Ability that allows the owning Character to perform a jump.
 * This ability is used to test the fundamental activation and execution flow of simple, 
 * instant Abilities within the Gameplay Ability System (GAS).
 */
UCLASS()
class GASABILITIES_API UMyJumpAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:

	// Override the OnGiveAbility function to set up any necessary initialization
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;

	// Override the ActivateAbility function to implement the jump logic
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	
};
