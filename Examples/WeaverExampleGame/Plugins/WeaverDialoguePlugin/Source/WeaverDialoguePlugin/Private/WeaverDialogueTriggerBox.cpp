// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaverDialogueTriggerBox.h"
#include "Modules/ModuleManager.h"
#include "../Public/WeaverDialoguePlugin.h"

AWeaverDialogueTriggerBox::AWeaverDialogueTriggerBox()
{
	OnActorBeginOverlap.AddDynamic(this, &AWeaverDialogueTriggerBox::OverlapEvent);
}

void AWeaverDialogueTriggerBox::OverlapEvent(AActor* overlappedActor, AActor* otherActor)
{
	if (otherActor && otherActor != this)
	{
		if (FModuleManager::Get().IsModuleLoaded("WeaverDialoguePlugin"))
		{
			FWeaverDialoguePluginModule& WeaverPluginModule = FModuleManager::GetModuleChecked<FWeaverDialoguePluginModule>("WeaverDialoguePlugin");
			const TArray<FString>& DialogueArray = WeaverPluginModule.GetDialogueArray();

			// Iterate through the Dialogue array and print each entry
			for (int32 i = 0; i < DialogueArray.Num(); i++)
			{
				UE_LOG(LogTemp, Log, TEXT("Dialogue %d: %s"), i + 1, *DialogueArray[i]);
			}
		}
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("WeaverDialoguePlugin Module is not loaded."));
	}
}

void AWeaverDialogueTriggerBox::BeginPlay()
{
	Super::BeginPlay();
}
