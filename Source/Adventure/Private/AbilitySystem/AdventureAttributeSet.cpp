#include "AbilitySystem/AdventureAttributeSet.h"

#include "Net/UnrealNetwork.h"

void UAdventureAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UAdventureAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAdventureAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
}

void UAdventureAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAdventureAttributeSet, Health, OldHealth)
}

void UAdventureAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAdventureAttributeSet, MaxHealth, OldMaxHealth)
}
