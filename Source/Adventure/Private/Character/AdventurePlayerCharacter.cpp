#include "Character/AdventurePlayerCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/AdventurePlayerState.h"


AAdventurePlayerCharacter::AAdventurePlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 540.f, 0.f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;
}

void AAdventurePlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	InitAbilityActorInfo();
}

void AAdventurePlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	InitAbilityActorInfo();
}

void AAdventurePlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	InitAbilityActorInfo();
}

void AAdventurePlayerCharacter::InitAbilityActorInfo()
{
	Super::InitAbilityActorInfo();
	AAdventurePlayerState* PlayerState = Cast<AAdventurePlayerState>(GetPlayerState());
	checkf(PlayerState, TEXT("AAdventurePlayerCharacter::InitAbilityActorInfo: PlayerState is null. Make sure the PlayerState is set correctly in the GameMode."));
	PlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(PlayerState, this);
	AbilitySystemComponent = PlayerState->GetAbilitySystemComponent();
	AttributeSet = PlayerState->GetAttributeSet();
}


