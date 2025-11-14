// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#include "02_Advanced/Kai/Characters/KaiEnemyCharacter.h"
#include "02_Advanced/Kai/AbilitySystem/KaiAbilitySystemComponent.h"
#include "02_Advanced/Kai/AbilitySystem/KaiAttributeSet.h"

// Sets default values
AKaiEnemyCharacter::AKaiEnemyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	AbilitySystemComponent = CreateDefaultSubobject<UKaiAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	
	AttributeSet = CreateDefaultSubobject<UKaiAttributeSet>("AttributeSet");
}

// Called when the game starts or when spawned
void AKaiEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	GiveDefaultAbilities();
	
	InitDefaultAttributes();
}