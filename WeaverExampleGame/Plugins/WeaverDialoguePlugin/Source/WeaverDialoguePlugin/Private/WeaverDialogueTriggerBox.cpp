// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaverDialogueTriggerBox.h"

AWeaverDialogueTriggerBox::AWeaverDialogueTriggerBox()
{
	OnActorBeginOverlap.AddDynamic(this, &AWeaverDialogueTriggerBox::OverlapEvent);
}

void AWeaverDialogueTriggerBox::OverlapEvent(AActor* overlappedActor, AActor* otherActor)
{
	if (otherActor && otherActor != this)
	{
		// print dialogue line(s)
	}
}

void AWeaverDialogueTriggerBox::BeginPlay()
{
	Super::BeginPlay();
}
