// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "KaiCharacterBase.generated.h"

class UGameplayAbility;
class UKaiAbilitySystemComponent;
class UKaiAttributeSet;
class UGameplayEffect;

UCLASS()
class GASABILITIES_API AKaiCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AKaiCharacterBase();
	
	// ~ IAbilitySystemInterface interface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	// ~ End of IAbilitySystemInterface interface	
	
	// Attribute Set Getter
	UKaiAttributeSet* GetAttributeSet() const;
	
protected:
	UPROPERTY()
	TObjectPtr<UKaiAbilitySystemComponent> AbilitySystemComponent;
	
	// Default Abilities
	UPROPERTY(EditDefaultsOnly, Category = Ability)
	TArray<TSubclassOf<UGameplayAbility>> DefaultAbilities;
	
	// Attributes
	UPROPERTY()
	TObjectPtr<UKaiAttributeSet> AttributeSet;
	
	void GiveDefaultAbilities();
	
	// Default Attribute Effect
	UPROPERTY(EditDefaultsOnly, Category = Ability)
	TSubclassOf<UGameplayEffect> DefaultAttributeEffect;
	
	void InitDefaultAttributes() const;
};
