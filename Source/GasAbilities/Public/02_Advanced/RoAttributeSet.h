// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "RoAttributeSet.generated.h"

// Macros to easily declare attributes
#define \
ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class GASABILITIES_API URoAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	// Current health attribute of the character
	UPROPERTY(BlueprintReadOnly, Category = Health, ReplicatedUsing = OnRep_CurrentHealth)
	FGameplayAttributeData CurrentHealth;
	ATTRIBUTE_ACCESSORS(URoAttributeSet, CurrentHealth)

	// Maximum health attribute of the character
	UPROPERTY(BlueprintReadOnly, Category = Health, ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(URoAttributeSet, MaxHealth)
	
	// Constructor
	URoAttributeSet();
	
protected:
	/// Replication notification functions

	// Called when CurrentHealth is replicated
	UFUNCTION(Category = Health)
	virtual void OnRep_CurrentHealth(const FGameplayAttributeData& OldCurrentHealth);

	// Called when MaxHealth is replicated
	UFUNCTION(Category = Health)
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);
	
	// Function that runs before any attribute base value is changed, allowing for clamping or validation
	virtual void PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const override;
	
	// Handles additional logic after a gameplay effect modifies an attribute
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	
	// Defines which properties should be replicated for this attribute set
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
