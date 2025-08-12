// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WarriorBaseAnimInstance.h"
#include "WarriorCharacterAnimInstance.generated.h"

class UCharacterMovementComponent;
class AWarriorBaseCharacter;

/**
 * 
 */
UCLASS()
class PROJECTW_API UWarriorCharacterAnimInstance : public UWarriorBaseAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY()
	TObjectPtr<AWarriorBaseCharacter> OwningCharacter = nullptr;

	UPROPERTY()
	TObjectPtr<UCharacterMovementComponent> OwningMovementComponent = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AnimData|LocomotionData")
	float GroundSpeed = 0.f;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AnimData|LocomotionData")
	bool bHasAcceleration = false;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AnimData|LocomotionData")
	float LocomotionDirection = 0.f;
};
