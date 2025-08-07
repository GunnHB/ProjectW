// Fill out your copyright notice in the Description page of Project Settings.


#include "WarriorWidgetBase.h"

#include "ProjectW/Interfaces/PawnUIInterface.h"

void UWarriorWidgetBase::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (IPawnUIInterface* PawnUIInterface = Cast<IPawnUIInterface>(GetOwningPlayerPawn()))
	{
		if (UHeroUIComponent* HeroUIComponent = PawnUIInterface->GetHeroUIComponent())
			BP_OnOwningHeroUIComponentInitialized(HeroUIComponent);
	}
}
