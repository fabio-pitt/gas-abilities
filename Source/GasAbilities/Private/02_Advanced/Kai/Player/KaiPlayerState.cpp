// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#include "02_Advanced/Kai/Player/KaiPlayerState.h"
#include "02_Advanced/Kai/AbilitySystem/KaiAbilitySystemComponent.h"
#include "02_Advanced/Kai/AbilitySystem/KaiAttributeSet.h"

AKaiPlayerState::AKaiPlayerState()
{
	SetNetUpdateFrequency(100.f);
	
	AbilitySystemComponent = CreateDefaultSubobject<UKaiAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
	AttributeSet = CreateDefaultSubobject<UKaiAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* AKaiPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UKaiAttributeSet* AKaiPlayerState::GetAttributeSet() const
{
	return AttributeSet;
}
