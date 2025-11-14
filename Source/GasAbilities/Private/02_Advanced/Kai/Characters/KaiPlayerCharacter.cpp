// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#include "02_Advanced/Kai/Characters/KaiPlayerCharacter.h"
#include "02_Advanced/Kai/AbilitySystem/KaiAbilitySystemComponent.h"
#include "02_Advanced/Kai/Player/KaiPlayerState.h"

// Sets default values
AKaiPlayerCharacter::AKaiPlayerCharacter()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AKaiPlayerCharacter::InitAbilitySystemComponent()
{
	AKaiPlayerState* KaiPlayerState = GetPlayerState<AKaiPlayerState>();
	check(KaiPlayerState);
	
	AbilitySystemComponent = CastChecked<UKaiAbilitySystemComponent>(KaiPlayerState->GetAbilitySystemComponent());
	AbilitySystemComponent->InitAbilityActorInfo(KaiPlayerState, this);
	
	AttributeSet = KaiPlayerState->GetAttributeSet();
}

void AKaiPlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	InitAbilitySystemComponent();
	GiveDefaultAbilities();
	
	InitDefaultAttributes();
}

void AKaiPlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	
	InitAbilitySystemComponent();
	
	InitDefaultAttributes();
}
