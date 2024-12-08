// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "WeaverDialoguePlugin.generated.h"

class FJsonObject;

USTRUCT()
struct FDialogueData
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<FString> Dialogue;
};

class FWeaverDialoguePluginModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
private:
	FString ReadStringFromFile(FString FilePath, bool& bOutSucces, FString& OutInfoMessage);
	TSharedPtr<FJsonObject> ReadJsonFromFile(FString JsonFilePath, bool& bOutSucces, FString& OutInfoMessage);
	FDialogueData ReadStructFromJsonFile(FString JsonFilePath, bool& bOutSucces, FString& OutInfoMessage);
private:
	FString filePath;
};
