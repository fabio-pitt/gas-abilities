// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#include "GasCharacterControllerBase.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Core/CharacterBase/GasCharacterBase.h"

// Setup input component
void AGasCharacterControllerBase::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Cast the InputComponent to UEnhancedInputComponent for enhanced input handling
	EnhancedInputComponent = Cast<UEnhancedInputComponent>(this->InputComponent);
	if (EnhancedInputComponent == nullptr) return;

	// Bind input actions to their respective handlers
	
	// Look - bind to Triggered event
	EnhancedInputComponent->BindAction(LookAction.Get(), ETriggerEvent::Triggered, this, &AGasCharacterControllerBase::Look);

	// Move - bind to Triggered event
	EnhancedInputComponent->BindAction(MoveAction.Get(), ETriggerEvent::Triggered, this, &AGasCharacterControllerBase::Move);

	// Jump - bind to Started and Completed events
	EnhancedInputComponent->BindAction(JumpAction.Get(), ETriggerEvent::Started, this, &AGasCharacterControllerBase::JumpStart);
	EnhancedInputComponent->BindAction(JumpAction.Get(), ETriggerEvent::Completed, this, &AGasCharacterControllerBase::JumpStop);
}

// Called when possessing a pawn
void AGasCharacterControllerBase::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	// Cast the possessed pawn to AGasCharacterBase and store the reference
	this->CurrentCharacter = Cast<AGasCharacterBase>(InPawn);

	// Get the enhanced input local player subsystem
	const TObjectPtr<UEnhancedInputLocalPlayerSubsystem> InputLocalPlayerSubsystem
		= ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(this->GetLocalPlayer());

	// Add the current input mapping context to the input subsystem
	if (InputLocalPlayerSubsystem && CurrentMappingContext)
		InputLocalPlayerSubsystem->AddMappingContext(this->CurrentMappingContext.Get(), 0);
}

/// Input action handlers implementation

// Handle look input
void AGasCharacterControllerBase::Look(const FInputActionValue& Value)
{
	// Get the look axis vector from the input value and pass it to the current character
	const FVector2d LookAxisVector = Value.Get<FVector2d>();
	this->CurrentCharacter->Look(LookAxisVector);
}

// Handle move input
void AGasCharacterControllerBase::Move(const FInputActionValue& Value)
{
	// Get the movement vector from the input value and pass it to the current character
	const FVector2d MovementVector = Value.Get<FVector2d>();
	this->CurrentCharacter->Move(MovementVector);
}

// Handle jump input start
void AGasCharacterControllerBase::JumpStart()
{
	this->CurrentCharacter->Jump();
}

// Handle jump input stop
void AGasCharacterControllerBase::JumpStop()
{
	this->CurrentCharacter->StopJumping();
}