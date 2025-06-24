// Fill out your copyright notice in the Description page of Project Settings.


#include "WarriorHeroAnimInstance.h"

#include "ProjectW/Characters/WarriorBaseCharacter.h"
#include "ProjectW/Characters/WarriorHeroCharacter.h"

void UWarriorHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	if (IsValid(OwningCharacter))
		OwningHeroCharacter = Cast<AWarriorHeroCharacter>(OwningCharacter);
}

void UWarriorHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	if (bHasAcceleration)
	{
		IdleElapsedTime = 0.f;
		bShouldEnterRelaxState = false;
	}
	else
	{
		IdleElapsedTime += DeltaSeconds;
		bShouldEnterRelaxState = (IdleElapsedTime >= EnterRelaxStateThreshold);
	}
}
