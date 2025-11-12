// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#include "01_Fundamentals/Abilities/MyJumpAbility.h"
#include "GameFramework/Character.h"
#include "AbilitySystemComponent.h"

void UMyJumpAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);

	// Add the "Ability.Jump" tag to this ability for identification
	AbilityTags.AddTag(FGameplayTag::RequestGameplayTag(FName("Ability.Jump")));
}

void UMyJumpAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                     const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                     const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	// Log the activation of the ability
	UE_LOG(LogTemp, Warning, TEXT("%s"), *FString(__FUNCTION__));

	// Check if the actor has a valid Character reference
	if (ACharacter* MyCharacter = Cast<ACharacter>(ActorInfo->AvatarActor.Get()))
		MyCharacter->Jump();

	// End the ability immediately after performing the jump
	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
