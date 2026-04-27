#pragma once

#ifndef DIALOGUEMANAGER_H
#define DIALOGUEMANAGER_H

#ifdef _WIN32
#ifdef STORYSTACKLIBRARY_EXPORTS
#define STORYSTACKLIBRARY_API __declspec(dllexport)
#else
#define STORYSTACKLIBRARY_API __declspec(dllimport)
#endif
#else
#define STORYSTACKLIBRARY_API
#endif

#include "Character.h"
#include "Scene.h"
#include "DialogueEntry.h"

namespace StoryStack
{
	STORYSTACKLIBRARY_API UUIDv4::UUID CreateCharacter(const std::string& newCharacterName);
	STORYSTACKLIBRARY_API UUIDv4::UUID CreateScene(const std::string& newSceneName);
	STORYSTACKLIBRARY_API UUIDv4::UUID AddDialogueToCharacter(const UUIDv4::UUID& sceneID, const UUIDv4::UUID& speakerID, DialogueTypes type, const std::string& dialogue);
	
	STORYSTACKLIBRARY_API void SetSpeaker(const UUIDv4::UUID& sceneID, const UUIDv4::UUID& lineID, const UUIDv4::UUID speakerID);
	STORYSTACKLIBRARY_API void SetLineText(const UUIDv4::UUID& sceneID, const UUIDv4::UUID& lineID, const std::string& text);

	STORYSTACKLIBRARY_API std::vector<std::string> GetCharacterNames();
	STORYSTACKLIBRARY_API const std::unordered_map<UUIDv4::UUID, Character>& GetCharacters();
	STORYSTACKLIBRARY_API const std::unordered_map<UUIDv4::UUID, Scene>& GetScenes();
	STORYSTACKLIBRARY_API UUIDv4::UUID GetSceneIdFromName(const std::string& name);
	STORYSTACKLIBRARY_API UUIDv4::UUID GetCharacterIdFromName(const std::string& name);
	STORYSTACKLIBRARY_API std::string GetSceneNameFromID(const UUIDv4::UUID& id);
	STORYSTACKLIBRARY_API std::string GetCharacterNameFromID(const UUIDv4::UUID& id);
}

#endif // !DIALOGUEMANAGER_H

