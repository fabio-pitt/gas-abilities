// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#include "02_Advanced/Kai/Characters/KaiCharacterBase.h"
#include "02_Advanced/Kai/AbilitySystem/KaiAbilitySystemComponent.h"

// Sets default values
AKaiCharacterBase::AKaiCharacterBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

UAbilitySystemComponent* AKaiCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
