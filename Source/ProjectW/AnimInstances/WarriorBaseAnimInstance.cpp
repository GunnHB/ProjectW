// Fill out your copyright notice in the Description page of Project Settings.


#include "WarriorBaseAnimInstance.h"

#include "ProjectW/WarriorFunctionLibrary.h"

bool UWarriorBaseAnimInstance::DoesOwnerHaveTag(FGameplayTag TagToCheck) const
{
	if (APawn* OwningPawn = TryGetPawnOwner())
		return UWarriorFunctionLibrary::NativeDoesActorHaveTag(OwningPawn, TagToCheck);

	return false;
}
