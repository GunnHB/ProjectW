// Fill out your copyright notice in the Description page of Project Settings.


#include "WarriorCharacterAnimInstance.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "ProjectW/Characters/WarriorBaseCharacter.h"

void UWarriorCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	OwningCharacter = Cast<AWarriorBaseCharacter>(TryGetPawnOwner());
	if (IsValid(OwningCharacter))
		OwningMovementComponent = OwningCharacter->GetCharacterMovement();
}

void UWarriorCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	if (IsValid(OwningCharacter) == false || IsValid(OwningMovementComponent) == false)
		return;

	GroundSpeed = OwningCharacter->GetVelocity().Size2D();
	bHasAcceleration = OwningMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.f;
}
