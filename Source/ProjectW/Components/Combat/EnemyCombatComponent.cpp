// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCombatComponent.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "ProjectW/DebugHelper.h"
#include "ProjectW/WarriorFunctionLibrary.h"
#include "ProjectW/WarriorGameplayTags.h"

void UEnemyCombatComponent::OnHitTargetActor(AActor* HitActor)
{
	if (OverlappedActors.Contains(HitActor))
		return;

	OverlappedActors.AddUnique(HitActor);

	// todo: implement block check
	bool bIsValidBlock = false;
	
	const bool bIsPlayerBlocking = UWarriorFunctionLibrary::NativeDoesActorHaveTag(HitActor, WarriorGameplayTags::Player_Status_Blocking);
	const bool bIsMyAttackUnblockable = false;

	if (bIsPlayerBlocking && bIsMyAttackUnblockable == false)
		bIsValidBlock = UWarriorFunctionLibrary::IsValidBlock(GetOwningPawn(), HitActor);

	FGameplayEventData EventData;
	EventData.Instigator = GetOwningPawn();
	EventData.Target = HitActor;

	if (bIsValidBlock)
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(HitActor, WarriorGameplayTags::Player_Event_SuccessfulBlock, EventData);
	else
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(GetOwningPawn(), WarriorGameplayTags::Shared_Event_MeleeHit, EventData);
}
