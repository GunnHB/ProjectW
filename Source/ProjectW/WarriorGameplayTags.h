// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "NativeGameplayTags.h"

namespace WarriorGameplayTags
{
	/** Input Tags **/
	PROJECTW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move);
	PROJECTW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look);
	PROJECTW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_EquipAxe);
	PROJECTW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_UnequipAxe);

	/** Player Tags **/
	PROJECTW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Equip_Axe);
	PROJECTW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Unequip_Axe);
	
	PROJECTW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Axe);

	PROJECTW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Equip_Axe);
	PROJECTW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Unequip_Axe);
}
