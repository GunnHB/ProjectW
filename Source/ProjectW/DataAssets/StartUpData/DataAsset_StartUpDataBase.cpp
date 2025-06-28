// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAsset_StartUpDataBase.h"

#include "ProjectW/AbilitySystem/WarriorAbilitySystemComponent.h"
#include "ProjectW/AbilitySystem/Abilities/WarriorGameplayAbility.h"

void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InWarriorASCToGive, int32 ApplyLevel)
{
	check(InWarriorASCToGive);

	GrantAbilities(ActivateOnGivenAbilities, InWarriorASCToGive, ApplyLevel);
	GrantAbilities(ReactivateAbilities, InWarriorASCToGive, ApplyLevel);
}

void UDataAsset_StartUpDataBase::GrantAbilities(const TArray<TSubclassOf<UWarriorGameplayAbility>>& InAbilitiesToGive, UWarriorAbilitySystemComponent* InWarriorASCToGive, int32 ApplyLevel)
{
	if (InAbilitiesToGive.IsEmpty())
		return;

	for (const TSubclassOf<UWarriorGameplayAbility>& Ability : InAbilitiesToGive)
	{
		if (Ability == nullptr)
			continue;

		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InWarriorASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		
		InWarriorASCToGive->GiveAbility(AbilitySpec);
	}
}
