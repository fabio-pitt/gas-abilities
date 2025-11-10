// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GasGameModeAbilities.generated.h"

/**
 * AGasGameMode is the primary Game Mode for the GasAbilities project. 
 * It handles the fundamental rules of the game, including the default Pawn, and setting up the initial classes.
 * This class is designed to provide the necessary game context and rules for the project utilizing the
 * Unreal Engine's Gameplay Ability System (GAS).
*/
UCLASS()
class GASABILITIES_API AGasGameModeAbilities : public AGameModeBase
{
	GENERATED_BODY()

public:
	// Sets default values for this game mode's properties
	AGasGameModeAbilities();
};
