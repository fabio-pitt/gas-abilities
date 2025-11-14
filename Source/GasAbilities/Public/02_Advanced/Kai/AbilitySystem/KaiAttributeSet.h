// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "KaiAttributeSet.generated.h"

// Define copied from AttributeSet.h to simplify accessors creation
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
		GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class GASABILITIES_API UKaiAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UKaiAttributeSet();
	
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	
	// HEALTH
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Ability | Gameplay Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UKaiAttributeSet, Health)
	
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;
	
	// MAX HEALTH
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Ability | Gameplay Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UKaiAttributeSet, MaxHealth)
	
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;
	
	// STAMINA
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Stamina, Category = "Ability | Gameplay Attributes")
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UKaiAttributeSet, Stamina)
	
	UFUNCTION()
	void OnRep_Stamina(const FGameplayAttributeData& OldStamina) const;
	
	// MAX STAMINA
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxStamina, Category = "Ability | Gameplay Attributes")
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UKaiAttributeSet, MaxStamina)
	
	UFUNCTION()
	void OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) const;
	
	// STRENGTH
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Strength, Category = "Ability | Gameplay Attributes")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UKaiAttributeSet, Strength)
	
	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength) const;
	
	// MAX STRENGTH
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxStrength, Category = "Ability | Gameplay Attributes")
	FGameplayAttributeData MaxStrength;
	ATTRIBUTE_ACCESSORS(UKaiAttributeSet, MaxStrength)
	
	UFUNCTION()
	void OnRep_MaxStrength(const FGameplayAttributeData& OldMaxStrength) const;
};
