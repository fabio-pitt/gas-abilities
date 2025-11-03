// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#include "Core/GasPlayerController.h"

// Setup input component and bind abilities to input
void AGasPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Check if the AbilitySystemComponent is valid
	if (AbilitySystemComponent)
	{
		// Bind ability activation to the input component
		AbilitySystemComponent->BindAbilityActivationToInputComponent(this->InputComponent, FGameplayAbilityInputBinds(
			TEXT("Confirm"),
			TEXT("Cancel"),
			FTopLevelAssetPath(TEXT("/Script/GASProject"), TEXT("EAbilityInputID")),
			static_cast<int32>(EAbilityInputID::Confirm),
			static_cast<int32>(EAbilityInputID::Cancel)
		));
	}
	else UE_LOG(LogTemp, Error, TEXT("AbilitySystemComponent is null"));
}

// Add character abilities to the Ability System Component
void AGasPlayerController::AddCharacterAbilities()
{
	// Check if the AbilitySystemComponent is valid
	if (AbilitySystemComponent == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("AbilitySystemComponent is null"));
		return;
	}

	// For each ability in the DefaultAbilities array, give it to the AbilitySystemComponent
	for (TSubclassOf<UGameplayAbility> AbilityClass : DefaultAbilities)
	{
		if (AbilityClass) AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(
			AbilityClass, 1, static_cast<int32>(EAbilityInputID::Confirm), this));

		else UE_LOG(LogTemp, Warning, TEXT("An AbilityClass is null"));
	}
}

// Called when the game starts or when spawned
void AGasPlayerController::BeginPlay()
{
	Super::BeginPlay();
	AddCharacterAbilities(); // Add the character abilities at the start of the game
}