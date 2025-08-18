// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCombatComponent.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "ProjectW/DebugHelper.h"
#include "ProjectW/WarriorGameplayTags.h"

void UEnemyCombatComponent::OnHitTargetActor(AActor* HitActor)
{
	if (OverlappedActors.Contains(HitActor))
		return;

	OverlappedActors.AddUnique(HitActor);

	// todo: implement block check
	bool bIsValidBlock = false;
	
	const bool bIsPlayerBlocking = false;
	const bool bIsMyAttackUnblockable = false;

	if (bIsPlayerBlocking && !bIsMyAttackUnblockable)
	{
		// todo: check if the block is valid
	}

	FGameplayEventData EventData;
	EventData.Instigator = GetOwningPawn();
	EventData.Target = HitActor;

	if (bIsValidBlock)
	{
		// todo: handle successful block
	}
	else
	{
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(GetOwningPawn(), WarriorGameplayTags::Shared_Event_MeleeHit, EventData
			);
	}
}
