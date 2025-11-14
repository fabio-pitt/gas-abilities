// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "KaiPlayerState.generated.h"

class UKaiAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class GASABILITIES_API AKaiPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:
	AKaiPlayerState();
	
	// ~ IAbilitySystemInterface interface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	// ~ End of IAbilitySystemInterface interface
	
protected:
	UPROPERTY()
	TObjectPtr<UKaiAbilitySystemComponent> AbilitySystemComponent;
};
