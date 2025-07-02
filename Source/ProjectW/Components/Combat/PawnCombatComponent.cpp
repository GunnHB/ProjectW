// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnCombatComponent.h"

#include "ProjectW/DebugHelper.h"
#include "ProjectW/Items/Weapons/WarriorWeaponBase.h"

void UPawnCombatComponent::RegisterSpawnWeapon(FGameplayTag InWeaponTagToRegister, AWarriorWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon)
{
	checkf(CharacterCarriedWeaponMap.Contains(InWeaponTagToRegister) == false, TEXT("a named %s has already been added as carried weapon"), *InWeaponTagToRegister.ToString());
	check(InWeaponToRegister);

	CharacterCarriedWeaponMap.Emplace(InWeaponTagToRegister, InWeaponToRegister);

	if (bRegisterAsEquippedWeapon)
		CurrentEquippedWeaponTag = InWeaponTagToRegister;

	const FString WeaponString = FString::Printf(TEXT("a weapon named: %s has been registered using the tag %s"), *InWeaponToRegister->GetName(), *InWeaponTagToRegister.ToString());
	Debug::Print(WeaponString);
}

AWarriorWeaponBase* UPawnCombatComponent::GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const
{
	if (CharacterCarriedWeaponMap.Contains(InWeaponTagToGet))
	{
		// 상수 포인터를 가리키는 포인터
		if (AWarriorWeaponBase* const* FoundWeapon = CharacterCarriedWeaponMap.Find(InWeaponTagToGet))
			return *FoundWeapon;
	}

	return nullptr;
}

AWarriorWeaponBase* UPawnCombatComponent::GetCharacterCurrentEquippedWeapon() const
{
	if (CurrentEquippedWeaponTag.IsValid() == false)
		return nullptr;

	return GetCharacterCarriedWeaponByTag(CurrentEquippedWeaponTag);
}
