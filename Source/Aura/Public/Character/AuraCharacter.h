// Copyright my own damn self, it's just a learning project

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "AuraCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()


public:
	AAuraCharacter();
	virtual void PossessedBy(AController* NewOwner) override;
	virtual void OnRep_PlayerState() override;

private:
	void InitAbilityActorInfo();	
};
