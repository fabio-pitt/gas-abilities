// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GasCharacterBase.generated.h"

class UCameraComponent;
class USpringArmComponent;

/**
 * AGasCharacterBase is an **abstract** base class for all playable Characters in the project.
 * It establishes the core functionality and component structure inherited by all derived characters.
 * This class provides the foundational architecture and replication setup for Characters, 
 * ensuring derived classes can seamlessly integrate the Gameplay Ability System.
 */
UCLASS(Abstract, NotBlueprintable)
class GASABILITIES_API AGasCharacterBase : public ACharacter
{
	GENERATED_BODY()

	// The Camera Arm Component that positions the camera relative to the character.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = GAS_Camera, meta = (AllowPrivateAccess = true))
	TObjectPtr<USpringArmComponent> CameraArmComponent;

	// The Camera Component for the character that provides the player's viewpoint.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = GAS_Camera, meta = (AllowPrivateAccess = true))
	TObjectPtr<UCameraComponent> CameraComponent;

public:
	// Sets default values for this character's properties
	AGasCharacterBase();
	
	// Handler for Look action
	void Look(FVector2d LookAxisVector);

	// Handler for Move action
	void Move(FVector2d MovementVector);
};
