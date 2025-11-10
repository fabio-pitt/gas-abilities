// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#pragma once

#include "CoreMinimal.h"
#include "Core/Base/Controller/GasControllerBase.h"
#include "GasControllerAbilities.generated.h"

// Define the Ability Input ID enumeration
UENUM(BlueprintType)
enum class EGasAbilityInputID : uint8
{
	None	UMETA(DisplayName = "None"),
	Confirm UMETA(DisplayName = "Confirm"),
	Cancel	UMETA(DisplayName = "Cancel")
};

/**
 * AGasController is the concrete Player Controller derived from AGasControllerBase.
 * It extends the base input handling by managing the **binding of Ability inputs**
 * directly to the Character's Gameplay Ability System (GAS). 
 * This class serves as the essential link between player commands and the execution 
 * of all Gameplay Abilities and related GAS functionality.
 */
UCLASS(Blueprintable)
class GASABILITIES_API AGasControllerAbilities : public AGasControllerBase
{
	GENERATED_BODY()

protected:

	/// Declare properties

	// The Input Mapping Context that defines the GAS input scheme for the character.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|GAS", meta = (AllowPrivateAccess = true))
	TObjectPtr<UInputMappingContext> GasMappingContext;

	// Reference to the current Gas Character controlled by this controller.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Input|GAS", meta = (AllowPrivateAccess = true))
	TObjectPtr<class AGasCharacterAbilities> GasCharacter;

	/// Declare GAS input actions for movement and looking around

	// Input action for looking around
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|GAS|Actions", meta = (AllowPrivateAccess = true))
	TObjectPtr<UInputAction> SpecialJumpAction;

	/// Setup
	
	// Called when the controller is possessing a pawn
	virtual void OnPossess(APawn* InPawn) override;

	// Function to bind the abilities
	void BindAbilities();

	/// Input action handlers implementation

	// Handler for Special Jump input
	void SpecialJump();
};
