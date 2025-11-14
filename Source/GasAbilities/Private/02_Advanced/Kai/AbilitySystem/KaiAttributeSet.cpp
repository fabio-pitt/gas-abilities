// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#include "02_Advanced/Kai/AbilitySystem/KaiAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"

UKaiAttributeSet::UKaiAttributeSet()
{
	InitHealth(100.f);
}

void UKaiAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UKaiAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UKaiAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UKaiAttributeSet, Stamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UKaiAttributeSet, MaxStamina, COND_None, REPNOTIFY_Always);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UKaiAttributeSet, Strength, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UKaiAttributeSet, MaxStrength, COND_None, REPNOTIFY_Always);
}

// HEALTH
void UKaiAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UKaiAttributeSet, Health, OldHealth);
}

void UKaiAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UKaiAttributeSet, MaxHealth, OldMaxHealth);
}

// STAMINA
void UKaiAttributeSet::OnRep_Stamina(const FGameplayAttributeData& OldStamina) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UKaiAttributeSet, Stamina, OldStamina);
}

void UKaiAttributeSet::OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UKaiAttributeSet, MaxStamina, OldMaxStamina);
}

// STRENGTH
void UKaiAttributeSet::OnRep_Strength(const FGameplayAttributeData& OldStrength) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UKaiAttributeSet, Strength, OldStrength);
}

void UKaiAttributeSet::OnRep_MaxStrength(const FGameplayAttributeData& OldMaxStrength) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UKaiAttributeSet, MaxStrength, OldMaxStrength);
}
