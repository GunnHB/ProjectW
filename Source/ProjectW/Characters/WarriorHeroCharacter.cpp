// Fill out your copyright notice in the Description page of Project Settings.


#include "WarriorHeroCharacter.h"

#include "../DebugHelper.h"

void AWarriorHeroCharacter::BeginPlay()
{
	Super::BeginPlay();

	Debug::Print(TEXT("Working"));
}
