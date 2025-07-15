// Fill out your copyright notice in the Description page of Project Settings.


#include "WarriorEnemyGameplayAbility.h"

#include "ProjectW/Characters/WarriorEnemyCharacter.h"

AWarriorEnemyCharacter* UWarriorEnemyGameplayAbility::GetEnemyCharacterFromActorInfo()
{
	if (CachedWarriorEnemyCharacter.IsValid() == false)
		CachedWarriorEnemyCharacter = Cast<AWarriorEnemyCharacter>(CurrentActorInfo->AvatarActor);

	return CachedWarriorEnemyCharacter.IsValid() ? CachedWarriorEnemyCharacter.Get() : nullptr;
}

UEnemyCombatComponent* UWarriorEnemyGameplayAbility::GetEnemyCombatComponent()
{
	return GetEnemyCharacterFromActorInfo()->GetEnemyCombatComponent();
}
