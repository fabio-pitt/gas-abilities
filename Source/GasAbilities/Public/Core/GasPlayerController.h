// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#pragma once

#include "CoreMinimal.h"
#include "Core/CharacterControllerBase/GasPlayerControllerBase.h"
#include "AbilitySystemComponent.h"
#include "GasPlayerController.generated.h"

// Define the enum for Ability input ID
UENUM(BlueprintType)
enum EAbilityInputID : uint8
{
	None	UMETA(DisplayName = "None"),
	Confirm	UMETA(DisplayName = "Confirm"),
	Cancel	UMETA(DisplayName = "Cancel")
};

/**
 * AGasPlayerController is the concrete Player Controller implementation derived from AGasPlayerControllerBase.
 * It handles the full setup of player input and is specifically responsible for **binding input actions** * to the
 * Character's Gameplay Ability System (GAS). 
 * This class is the definitive link between player commands and the execution of Gameplay Abilities, 
 * managing the runtime input configuration required by GAS.
 */
UCLASS()
class GASABILITIES_API AGasPlayerController : public AGasPlayerControllerBase
{
	GENERATED_BODY()

	// The component that handles abilities
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = AbilitySystem, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	// The array containing the character's abilities
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GAS", meta = (AllowPrivateAccess = "true"))
	TArray<TSubclassOf<UGameplayAbility>> DefaultAbilities;

	// Called to bind functionality to input
	virtual void SetupInputComponent() override;

	// Add character abilities to the Ability System Component
	void AddCharacterAbilities();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
