// Copyright Epic Games, Inc. All Rights Reserved.

#include "WeaverDialoguePlugin.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FWeaverDialoguePluginModule"

void FWeaverDialoguePluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FWeaverDialoguePluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

FString FWeaverDialoguePluginModule::ReadStringFromFile(FString FilePath, bool& bOutSucces, FString& OutInfoMessage)
{
	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*FilePath))
	{
		bOutSucces = false;
		OutInfoMessage = FString::Printf(TEXT("File doesn't exist - '%s'"), *FilePath);
		return "";
	}

	FString RetString = "";

	if (!FFileHelper::LoadFileToString(RetString, *FilePath))
	{
		bOutSucces = false;
		OutInfoMessage = FString::Printf(TEXT("Was not able to read file - '%s'"), *FilePath);
		return "";
	}

	bOutSucces = true;
	OutInfoMessage = FString::Printf(TEXT("File was read - '%s'"), *FilePath);

	return RetString;
}

TSharedPtr<FJsonObject> FWeaverDialoguePluginModule::ReadJsonFromFile(FString JsonFilePath, bool& bOutSucces, FString& OutInfoMessage)
{
	FString JsonString = FWeaverDialoguePluginModule::ReadStringFromFile(JsonFilePath, bOutSucces, OutInfoMessage);
	if (!bOutSucces)
	{
		return nullptr;
	}

	TSharedPtr<FJsonObject> RetJsonObject;

	if (!FJsonSerializer::Deserialize(TJsonReaderFactory<>::Create(JsonString), RetJsonObject))
	{
		bOutSucces = false;
		OutInfoMessage = FString::Printf(TEXT("Was not able to deserialze the json string - '%s'"), *JsonString);
		return nullptr;
	}

	return RetJsonObject;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FWeaverDialoguePluginModule, WeaverDialoguePlugin)