#pragma once

#ifndef DIALOGUEMANAGER_H
#define DIALOGUEMANAGER_H

#ifdef _WIN32
#ifdef WEAVERLIBRARY_EXPORTS
#define WEAVERLIBRARY_API __declspec(dllexport)
#else
#define WEAVERLIBRARY_API __declspec(dllimport)
#endif
#else
#define WEAVERLIBRARY_API
#endif

#include "Character.h"
#include "Scene.h"
#include "DialogueEntry.h"

namespace Weaver
{
	WEAVERLIBRARY_API UUIDv4::UUID CreateCharacter(const std::string& newCharacterName);
	WEAVERLIBRARY_API UUIDv4::UUID CreateScene(const std::string& newSceneName);
	WEAVERLIBRARY_API UUIDv4::UUID AddDialogueToCharacter(const UUIDv4::UUID& sceneID, const UUIDv4::UUID& speakerID, Weaver::DialogueTypes type, const std::string& dialogue);
	
	WEAVERLIBRARY_API void SetSpeaker(const UUIDv4::UUID& sceneID, const UUIDv4::UUID& lineID, const UUIDv4::UUID speakerID);
	WEAVERLIBRARY_API void SetLineText(const UUIDv4::UUID& sceneID, const UUIDv4::UUID& lineID, const std::string& text);

	WEAVERLIBRARY_API std::vector<std::string> GetCharacterNames();
	WEAVERLIBRARY_API const std::unordered_map<UUIDv4::UUID, Character>& GetCharacters();
	WEAVERLIBRARY_API const std::unordered_map<UUIDv4::UUID, Scene>& GetScenes();
	WEAVERLIBRARY_API UUIDv4::UUID GetSceneIdFromName(const std::string& name);
	WEAVERLIBRARY_API UUIDv4::UUID GetCharacterIdFromName(const std::string& name);
	WEAVERLIBRARY_API std::string GetSceneNameFromID(const UUIDv4::UUID& id);
	WEAVERLIBRARY_API std::string GetCharacterNameFromID(const UUIDv4::UUID& id);
}

#endif // !DIALOGUEMANAGER_H

