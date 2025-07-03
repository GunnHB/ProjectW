// Fill out your copyright notice in the Description page of Project Settings.


#include "WarriorHeroGameplayAbility.h"

#include "ProjectW/Characters/WarriorHeroCharacter.h"
#include "ProjectW/Controllers/WarriorHeroController.h"

AWarriorHeroCharacter* UWarriorHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
	if (CacheWarriorHeroCharacter.IsValid() == false)
		CacheWarriorHeroCharacter = Cast<AWarriorHeroCharacter>(CurrentActorInfo->AvatarActor);

	return CacheWarriorHeroCharacter.IsValid() ? CacheWarriorHeroCharacter.Get() : nullptr;
}

AWarriorHeroController* UWarriorHeroGameplayAbility::GetHeroControllerFromActorInfo()
{
	if (CacheWarriorHeroController.IsValid() == false)
		CacheWarriorHeroController = Cast<AWarriorHeroController>(CurrentActorInfo->PlayerController);

	return CacheWarriorHeroController.IsValid() ? CacheWarriorHeroController.Get() : nullptr;
}

UHeroCombatComponent* UWarriorHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
	return GetHeroCharacterFromActorInfo()->GetHeroCombatComponent();
}
