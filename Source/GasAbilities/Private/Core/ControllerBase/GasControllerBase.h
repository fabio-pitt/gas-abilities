// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "Core/GasCharacter.h"
#include "GasControllerBase.generated.h"

struct FInputActionValue;

/**
 * AGasControllerBase is an **abstract** base Player Controller.
 * It provides the core functionality for managing the Character and handles **fundamental input mappings**, 
 * such as basic movement and camera control. This class establishes the foundation 
 * for common controller responsibilities, allowing derived classes to focus specifically 
 * on Gameplay Ability System (GAS) integration.
 */
UCLASS(Abstract, NotBlueprintable)
class GASABILITIES_API AGasControllerBase : public APlayerController
{
	GENERATED_BODY()

protected:

	/// Declare properties
	
	// The Input Mapping Context that defines the input scheme for the character.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Base", meta = (AllowPrivateAccess = true))
	TObjectPtr<UInputMappingContext> MainMappingContext;

	// Reference to the current Gas Character Base controlled by this controller.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Input|Base", meta = (AllowPrivateAccess = true))
	TObjectPtr<AGasCharacterBase> CurrentCharacter;
	
	// The Enhanced Input Component for handling input actions.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Input|Base", meta = (AllowPrivateAccess = true))
	TObjectPtr<UEnhancedInputComponent> EnhancedInputComponent;

	/// Declare input actions for movement and looking around

	// Input action for looking around
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Base|Actions", meta = (AllowPrivateAccess = true))
	TObjectPtr<UInputAction> LookAction;

	// Input action for moving
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Base|Actions", meta = (AllowPrivateAccess = true))
	TObjectPtr<UInputAction> MoveAction;

	// Input action for jumping
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Base|Actions", meta = (AllowPrivateAccess = true))
	TObjectPtr<UInputAction> JumpAction;

public:

	/// Setup
	
	// Called to bind functionality to input
	virtual void SetupInputComponent() override;

	// Called when the controlled is possessing a pawn
	virtual void OnPossess(APawn* InPawn) override;

	/// Input actions handlers

	// Handler for Look action
	void Look(const FInputActionValue& Value);

	// Handler for Move action
	void Move(const FInputActionValue& Value);

	// Handler for Jump action start
	void JumpStart();

	// Handler for Jump action stop
	void JumpStop();
};
