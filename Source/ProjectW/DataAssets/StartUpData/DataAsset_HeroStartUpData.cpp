// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAsset_HeroStartUpData.h"

#include "ProjectW/AbilitySystem/WarriorAbilitySystemComponent.h"
#include "ProjectW/AbilitySystem/Abilities/WarriorGameplayAbility.h"

void UDataAsset_HeroStartUpData::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);

	for (const FWarriorHeroAbilitySet& AbilitySet : HeroStartUpAbilitySets)
	{
		if (AbilitySet.IsValid() == false)
			continue;

		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);

		InASCToGive->GiveAbility(AbilitySpec);
	}
}
