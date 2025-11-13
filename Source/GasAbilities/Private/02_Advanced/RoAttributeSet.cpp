// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#include "02_Advanced/RoAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

// Constructor
URoAttributeSet::URoAttributeSet()
{
	CurrentHealth.SetBaseValue(100.f);
	CurrentHealth.SetCurrentValue(100.f);
	
	MaxHealth.SetBaseValue(100.f);
	MaxHealth.SetCurrentValue(100.f);
}

// Current Health replication notification
void URoAttributeSet::OnRep_CurrentHealth(const FGameplayAttributeData& OldCurrentHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URoAttributeSet, CurrentHealth, OldCurrentHealth);
}

// Max Health replication notification
void URoAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URoAttributeSet, MaxHealth, OldMaxHealth);
}

// Pre-attribute base change logic
void URoAttributeSet::PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
	Super::PreAttributeBaseChange(Attribute, NewValue);
	
	// Clamp the new value of CurrentHealth to not exceed MaxHealth
	if (Attribute == GetCurrentHealthAttribute())
	{
		// Ensure CurrentHealth does not exceed MaxHealth
		const float MaxHealthValue = MaxHealth.GetCurrentValue();
		NewValue = FMath::Clamp(NewValue, 0.f, MaxHealthValue);
	}
}

// Post-gameplay effect execution logic
void URoAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	
	// Check if the modified attribute is CurrentHealth
	if (Data.EvaluatedData.Attribute == GetCurrentHealthAttribute())
	{
		// Clamp CurrentHealth to be within valid range
		const float NewHealth = FMath::Clamp(CurrentHealth.GetCurrentValue(), 0.f, MaxHealth.GetCurrentValue());
		SetCurrentHealth(NewHealth);
	}
}

void URoAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME_CONDITION_NOTIFY(URoAttributeSet, CurrentHealth,	COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URoAttributeSet, MaxHealth,		COND_None, REPNOTIFY_Always);
}
