// Fill out your copyright notice in the Description page of Project Settings.


#include "WarriorBaseCharacter.h"

#include "ProjectW/AbilitySystem/WarriorAbilitySystemComponent.h"
#include "ProjectW/AbilitySystem/WarriorAttributeSet.h"

// Sets default values
AWarriorBaseCharacter::AWarriorBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;

	WarriorAbilitySystemComponent = CreateDefaultSubobject<UWarriorAbilitySystemComponent>(TEXT("WarriorAbilitySystemComponent"));
	WarriorAttributeSet = CreateDefaultSubobject<UWarriorAttributeSet>(TEXT("WarriorAttributeSet"));
}

UAbilitySystemComponent* AWarriorBaseCharacter::GetAbilitySystemComponent() const
{
	return GetWarriorAbilitySystemComponent();
}

void AWarriorBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (IsValid(WarriorAbilitySystemComponent))
	{
		// ASC를 사용하기 위해서 반드시 호출해야하는 함수
		// 해당 프로젝트에서는 오너와 아바타를 같은 액터로 세팅했지만 경우에 따라 다름
		WarriorAbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
}


