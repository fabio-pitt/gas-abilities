// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#include "GasAbilities/Public/Core/GasGameMode.h"

// Sets default values
AGasGameMode::AGasGameMode()
{
	// Set the default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT(
		"/Game/Blueprints/Characters/BP_MainCharacter"));

	// If the Blueprint class is found, set it as the default pawn class
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	
	// Set the default player controller class to our custom controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT(
		"/Game/Blueprints/Characters/BP_MainController"));

	// If the Blueprint class is found, set it as the default player controller class
	if (PlayerControllerBPClass.Class != nullptr)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
	else UE_LOG(LogTemp, Warning, TEXT("PlayerController class not found")) 
}
