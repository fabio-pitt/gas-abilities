// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#include "Core/Character_Attributes/GasControllerAttributes.h"
#include "Core/Character_Attributes/GasCharacterAttributes.h"
#include "EnhancedInputSubsystems.h"

// Called when possessing a pawn
void AGasControllerAttributes::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	// Cast the possessed pawn to AGasCharacter and store the reference
	this->GasCharacter = Cast<AGasCharacterAttributes>(InPawn);
	if (this->GasCharacter == nullptr) return;

	// Ensure the Ability System Component is valid
	// const TObjectPtr<UMyAbilitySystemComponent> AbilitySystemComponent = this->GasCharacter->GetAbilitySystemComponent();
	// if (AbilitySystemComponent == nullptr) return;

	// Get the enhanced input local player subsystem
	const TObjectPtr<UEnhancedInputLocalPlayerSubsystem> InputLocalPlayerSubsystem
		= ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(this->GetLocalPlayer());

	// Add the current input mapping context to the input subsystem
	if (InputLocalPlayerSubsystem && GasMappingContext)
		InputLocalPlayerSubsystem->AddMappingContext(this->GasMappingContext.Get(), 1);

	// // Bind the Special Jump ability to the input component
	// AbilitySystemComponent->BindAbilityActivationToInputComponent(InputComponent, FGameplayAbilityInputBinds(
	// 	"Confirm",
	// 	"Cancel",
	// 	"EGasAbilityInputID",
	// 	static_cast<int32>(EGasAbilityInputID::Confirm),
	// 	static_cast<int32>(EGasAbilityInputID::Confirm)
	// ));

	// Call the function to bind abilities
	BindAbilities();
}

// Function to bind the abilities
void AGasControllerAttributes::BindAbilities()
{
	// Ensure the Enhanced Input Component is valid
	if (EnhancedInputComponent == nullptr) return;

	// TODO: Bind actions
}
