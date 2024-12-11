// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/TriggerBox.h"
#include "WeaverDialogueTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class WEAVERDIALOGUEPLUGIN_API AWeaverDialogueTriggerBox : public ATriggerBox
{
	GENERATED_BODY()
public:
	AWeaverDialogueTriggerBox();

	UFUNCTION()
	void OverlapEvent(AActor* overlappedActor, AActor* otherActor);

protected:
	virtual void BeginPlay();
};
