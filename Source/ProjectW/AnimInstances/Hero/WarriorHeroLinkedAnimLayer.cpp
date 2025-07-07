// Fill out your copyright notice in the Description page of Project Settings.


#include "WarriorHeroLinkedAnimLayer.h"

#include "WarriorHeroAnimInstance.h"

UWarriorHeroAnimInstance* UWarriorHeroLinkedAnimLayer::GetHeroAnimInstance() const
{
	return Cast<UWarriorHeroAnimInstance>(GetOwningComponent()->GetAnimInstance());
}
