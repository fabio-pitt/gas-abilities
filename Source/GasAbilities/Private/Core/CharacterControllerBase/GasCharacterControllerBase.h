// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "GasCharacterControllerBase.generated.h"

class AGasCharacterBase;
struct FInputActionValue;

/**
 * AGasCharacterController is the Player Controller used for the main playable character in the project.
 * It is responsible for handling player input and **binding Ability inputs** to the 
 * Character's Gameplay Ability System (GAS). 
 * This controller manages the flow of commands and replication necessary for the player to utilize Abilities,
 * while also setting up the initial Player State and HUD for the GAS environment.
 */
UCLASS()
class GASABILITIES_API AGasCharacterControllerBase : public APlayerController
{
	GENERATED_BODY()

public:
	// The Input Mapping Context that defines the input scheme for the character.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = GAS_Input, meta = (AllowPrivateAccess = true))
	TObjectPtr<UInputMappingContext> CurrentMappingContext;

	// Reference to the current Gas Character Base controlled by this controller.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = GAS_Input, meta = (AllowPrivateAccess = true))
	TObjectPtr<AGasCharacterBase> CurrentCharacter;

	// The Enhanced Input Component for handling input actions.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = GAS_Input, meta = (AllowPrivateAccess = true))
	TObjectPtr<UEnhancedInputComponent> EnhancedInputComponent;

	/// Declare input actions for movement and looking around

	// Input action for looking around
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = GAS_Input, meta = (AllowPrivateAccess = true))
	TObjectPtr<UInputAction> LookAction;

	// Input action for moving
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = GAS_Input, meta = (AllowPrivateAccess = true))
	TObjectPtr<UInputAction> MoveAction;

	// Input action for jumping
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = GAS_Input, meta = (AllowPrivateAccess = true))
	TObjectPtr<UInputAction> JumpAction;

public:
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
