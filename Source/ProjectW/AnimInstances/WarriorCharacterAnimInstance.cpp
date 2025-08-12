// Fill out your copyright notice in the Description page of Project Settings.


#include "WarriorCharacterAnimInstance.h"

#include "GameFramework/CharacterMovementComponent.h"

#include "ProjectW/Characters/WarriorBaseCharacter.h"

#include "KismetAnimationLibrary.h"

void UWarriorCharacterAnimInstance::NativeInitializeAnimation()
{
	OwningCharacter = Cast<AWarriorBaseCharacter>(TryGetPawnOwner());
	if (IsValid(OwningCharacter) != false)
		OwningMovementComponent = OwningCharacter->GetCharacterMovement();
}

void UWarriorCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	// 애니메이션 쓰레드에서 동작
	// NativeUpdateAnimation에서 설정한 정보를 처리하여 애니메이션을 설정

	if (IsValid(OwningCharacter) == false || IsValid(OwningMovementComponent) == false)
		return;

	GroundSpeed = OwningCharacter->GetVelocity().Size2D();
	bHasAcceleration = OwningMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.f;

	LocomotionDirection = UKismetAnimationLibrary::CalculateDirection(OwningCharacter->GetVelocity(), OwningCharacter->GetActorRotation());
}
