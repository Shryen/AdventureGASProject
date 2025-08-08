#pragma once

#include "CoreMinimal.h"
#include "AdventureCharacterBase.h"
#include "AdventurePlayerCharacter.generated.h"

UCLASS()
class ADVENTURE_API AAdventurePlayerCharacter : public AAdventureCharacterBase
{
	GENERATED_BODY()

public:
	AAdventurePlayerCharacter();

protected:
	virtual void BeginPlay() override;
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	virtual void InitAbilityActorInfo() override;
	
};
