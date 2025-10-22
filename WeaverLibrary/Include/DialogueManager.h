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
	WEAVERLIBRARY_API UUIDv4::UUID AddDialogueToCharacter(UUIDv4::UUID sceneID, UUIDv4::UUID speakerID, Weaver::DialogueTypes type, const std::string& dialogue);
	
	WEAVERLIBRARY_API void SetSpeaker(UUIDv4::UUID sceneID, UUIDv4::UUID lineID, UUIDv4::UUID speakerID);
	WEAVERLIBRARY_API void SetLineText(UUIDv4::UUID sceneID, UUIDv4::UUID lineID, const std::string& text);

	WEAVERLIBRARY_API std::vector<std::string> GetCharacterNames();
	WEAVERLIBRARY_API std::unordered_map<UUIDv4::UUID, Character> GetCharacters();
	WEAVERLIBRARY_API std::unordered_map<UUIDv4::UUID, Scene> GetScenes();
	WEAVERLIBRARY_API UUIDv4::UUID GetSceneID(const std::string& name);
	WEAVERLIBRARY_API UUIDv4::UUID GetCharacterID(const std::string& name);

}

#endif // !DIALOGUEMANAGER_H

