// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#include "GasControllerBase.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

// Setup input component
void AGasControllerBase::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Check if InputComponent is valid
	if (this->InputComponent == nullptr) return;

	// Cast the InputComponent to UEnhancedInputComponent for enhanced input handling
	EnhancedInputComponent = Cast<UEnhancedInputComponent>(this->InputComponent);
	if (EnhancedInputComponent == nullptr) return;

	/// Bind input actions to their respective handlers
	
	// Look - bind to Triggered event
	EnhancedInputComponent->BindAction(LookAction.Get(), ETriggerEvent::Triggered, this, &AGasControllerBase::Look);

	// Move - bind to Triggered event
	EnhancedInputComponent->BindAction(MoveAction.Get(), ETriggerEvent::Triggered, this, &AGasControllerBase::Move);

	// Jump - bind to Started and Completed events
	EnhancedInputComponent->BindAction(JumpAction.Get(), ETriggerEvent::Started, this, &AGasControllerBase::JumpStart);
	EnhancedInputComponent->BindAction(JumpAction.Get(), ETriggerEvent::Completed, this, &AGasControllerBase::JumpStop);
}

// Called when possessing a pawn
void AGasControllerBase::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	// Cast the possessed pawn to AGasCharacterBase and store the reference
	this->GasCharacterBase = Cast<AGasCharacterBase>(InPawn);

	// Get the enhanced input local player subsystem
	const TObjectPtr<UEnhancedInputLocalPlayerSubsystem> InputLocalPlayerSubsystem
		= ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(this->GetLocalPlayer());

	// Add the current input mapping context to the input subsystem
	if (InputLocalPlayerSubsystem && MainMappingContext)
		InputLocalPlayerSubsystem->AddMappingContext(this->MainMappingContext.Get(), 0);
}

/// Input action handlers implementation

// Handle look input
void AGasControllerBase::Look(const FInputActionValue& Value)
{
	// Get the look axis vector from the input value and pass it to the current character
	const FVector2d LookAxisVector = Value.Get<FVector2d>();
	this->GasCharacterBase->Look(LookAxisVector);
}

// Handle move input
void AGasControllerBase::Move(const FInputActionValue& Value)
{
	// Get the movement vector from the input value and pass it to the current character
	const FVector2d MovementVector = Value.Get<FVector2d>();
	this->GasCharacterBase->Move(MovementVector);
}

// Handle jump input start
void AGasControllerBase::JumpStart()
{
	this->GasCharacterBase->Jump();
}

// Handle jump input stop
void AGasControllerBase::JumpStop()
{
	this->GasCharacterBase->StopJumping();
}