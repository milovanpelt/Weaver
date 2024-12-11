// Copyright Epic Games, Inc. All Rights Reserved.

#include "WeaverDialoguePlugin.h"
#include "Serialization/JsonSerializer.h"
#include "JsonObjectConverter.h"

#define LOCTEXT_NAMESPACE "FWeaverDialoguePluginModule"

void FWeaverDialoguePluginModule::StartupModule()
{
	filePath = "C:/Users/Xonar/Documents/GitHub/Weaver/WeaverDialogueBuilder/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/dialogue.json";

	bool bSuccess = false;
	FString InfoMessage;
	
	DialogueData = ReadStructFromJsonFile(filePath, bSuccess, InfoMessage);

	if (!bSuccess)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to read JSON File: %s"), *filePath);
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Successfully read JSON file: %s"), *InfoMessage);

		// Iterate through the Dialogue array and print each entry
		for (int32 Index = 0; Index < DialogueData.Dialogue.Num(); Index++)
		{
			UE_LOG(LogTemp, Log, TEXT("Dialogue %d: %s"), Index + 1, *DialogueData.Dialogue[Index]);
		}
	}
}

void FWeaverDialoguePluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

const TArray<FString>& FWeaverDialoguePluginModule::GetDialogueArray()
{
	return DialogueData.Dialogue;
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

FDialogueData FWeaverDialoguePluginModule::ReadStructFromJsonFile(FString JsonFilePath, bool& bOutSucces, FString& OutInfoMessage)
{
	TSharedPtr<FJsonObject> JsonObject = ReadJsonFromFile(JsonFilePath, bOutSucces, OutInfoMessage);
	if (!bOutSucces)
	{
		return FDialogueData();
	}

	FDialogueData RetDialogueData;

	if (!FJsonObjectConverter::JsonObjectToUStruct<FDialogueData>(JsonObject.ToSharedRef(), &RetDialogueData))
	{
		bOutSucces = false;
		OutInfoMessage = FString::Printf(TEXT("Was not able to convert data to struct - '%s'"), *JsonFilePath);
		return FDialogueData();
	}

	bOutSucces = true;
	OutInfoMessage = FString::Printf(TEXT("Read Json struct Succeeded - '%s'"), *JsonFilePath);
	return RetDialogueData;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FWeaverDialoguePluginModule, WeaverDialoguePlugin)