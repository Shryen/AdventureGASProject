#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "AdventurePlayerState.generated.h"

class UAttributeSet;
/**
 * 
 */
UCLASS()
class ADVENTURE_API AAdventurePlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
	public:
	AAdventurePlayerState();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override {return AbilitySystemComponent; }
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }

protected:
	UPROPERTY(BlueprintReadOnly, Category = "AbilitySystem")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	TObjectPtr<UAttributeSet> AttributeSet;
};
