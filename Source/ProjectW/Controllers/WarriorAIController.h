// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "WarriorAIController.generated.h"

struct FAIStimulus;
class UAISenseConfig_Sight;
/**
 * 
 */
UCLASS()
class PROJECTW_API AWarriorAIController : public AAIController
{
	GENERATED_BODY()

public:
	AWarriorAIController(const FObjectInitializer& ObjectInitializer);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UAIPerceptionComponent> EnemyPerceptionComponent = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UAISenseConfig_Sight> AISenseConfig_Sight = nullptr;

	UFUNCTION()
	virtual void OnEnemyPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);
};
