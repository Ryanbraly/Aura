// Copyright my own damn self, it's just a learning project


#include "Actor/AuraEffectActor.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"

#include "AbilitySystemInterface.h"

// Sets default values
AAuraEffectActor::AAuraEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;
	
	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
}



void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAuraEffectActor::ApplyEffectToTarget(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Target);
	if (TargetASC == nullptr) return;

	check(GameplayEffectClass);
	FGameplayEffectContextHandle EffectContextHandle = TargetASC -> MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle EffectSpecHandle = TargetASC -> MakeOutgoingSpec(GameplayEffectClass, 1.0f, EffectContextHandle);
	TargetASC -> ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
}


