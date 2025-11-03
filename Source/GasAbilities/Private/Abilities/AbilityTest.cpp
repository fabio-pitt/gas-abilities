// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#include "Abilities/AbilityTest.h"

void UAbilityTest::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
									const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (ActorInfo->AvatarActor.Get())
	{
		// Do the ability
		UE_LOG(LogTemp, Display, TEXT("Active Ability"));
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, TEXT("Ability Activated"));

		const FVector OwnerLocation = ActorInfo->AvatarActor.Get()->GetActorLocation();
		GetWorld()->SpawnActor<AActor>(ActorToSpawn, OwnerLocation, FRotator::ZeroRotator);
	}

	// End the ability
	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
