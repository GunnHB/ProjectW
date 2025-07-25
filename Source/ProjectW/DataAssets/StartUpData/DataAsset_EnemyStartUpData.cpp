// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAsset_EnemyStartUpData.h"

#include "ProjectW/AbilitySystem/WarriorAbilitySystemComponent.h"
#include "ProjectW/AbilitySystem/Abilities/WarriorEnemyGameplayAbility.h"

void UDataAsset_EnemyStartUpData::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);

	if (EnemyCombatAbilities.IsEmpty() == false)
	{
		for (TSubclassOf<UWarriorEnemyGameplayAbility>& AbilityClass : EnemyCombatAbilities)
		{
			if (AbilityClass == nullptr)
				continue;

			FGameplayAbilitySpec AbilitySpec(AbilityClass);
			AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
			AbilitySpec.Level = ApplyLevel;
			
			InASCToGive->GiveAbility(AbilitySpec);
		}
	}
}
