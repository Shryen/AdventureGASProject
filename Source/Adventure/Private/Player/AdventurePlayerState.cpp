#include "Player/AdventurePlayerState.h"

#include "AbilitySystemComponent.h"

AAdventurePlayerState::AAdventurePlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AttributeSet = CreateDefaultSubobject<UAttributeSet>("AttributeSet");
}
