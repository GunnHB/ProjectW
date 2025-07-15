// Fill out your copyright notice in the Description page of Project Settings.


#include "WarriorFunctionLibrary.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"

UWarriorAbilitySystemComponent* UWarriorFunctionLibrary::NativeGetWarriorASCFromActor(AActor* InActor)
{
	check(InActor);

	return CastChecked<UWarriorAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InActor));
}

void UWarriorFunctionLibrary::AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd)
{
	UWarriorAbilitySystemComponent* ACS = NativeGetWarriorASCFromActor(InActor);

	if (ACS->HasMatchingGameplayTag(TagToAdd))
		ACS->AddLooseGameplayTag(TagToAdd);
}

void UWarriorFunctionLibrary::RemoveGameplayTagFromActorIfFound(AActor* InActor, FGameplayTag TagToRemove)
{
	UWarriorAbilitySystemComponent* ACS = NativeGetWarriorASCFromActor(InActor);

	if (ACS->HasMatchingGameplayTag(TagToRemove))
		ACS->RemoveLooseGameplayTag(TagToRemove);
}

bool UWarriorFunctionLibrary::NativeDoseActorHaveTag(AActor* InActor, FGameplayTag TagToCheck)
{
	UWarriorAbilitySystemComponent* ACS = NativeGetWarriorASCFromActor(InActor);

	return ACS->HasMatchingGameplayTag(TagToCheck);
}

void UWarriorFunctionLibrary::BP_DoseActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, EWarriorConfirmType& OutConfirmType)
{
	OutConfirmType = NativeDoseActorHaveTag(InActor, TagToCheck) ? EWarriorConfirmType::Yes : EWarriorConfirmType::No; 
}
