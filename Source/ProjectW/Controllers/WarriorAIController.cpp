// Fill out your copyright notice in the Description page of Project Settings.


#include "WarriorAIController.h"

#include "Navigation/CrowdFollowingComponent.h"

#include "ProjectW/DebugHelper.h"

AWarriorAIController::AWarriorAIController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UCrowdFollowingComponent>("PathFollowingComponent"))
{
	if (UCrowdFollowingComponent* CrowdComp = Cast<UCrowdFollowingComponent>(GetPathFollowingComponent()))
		Debug::Print(TEXT("CrowdFollowingComponent valid"), FColor::Green);
}
