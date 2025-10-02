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
		static UUIDv4::UUID CreateCharacter(const std::string& newCharacterName);
		static std::vector<std::string> GetCharacterNames();
		static std::unordered_map<UUIDv4::UUID, Character> GetCharacters();
		static UUIDv4::UUID CreateScene(const std::string& newSceneName);
		static std::unordered_map<UUIDv4::UUID, Scene> GetScenes();
		static UUIDv4::UUID AddDialogueToCharacter(UUIDv4::UUID sceneID, UUIDv4::UUID speakerID, Weaver::DialogueTypes type, const std::string& dialogue);
		static void SetSpeaker(UUIDv4::UUID sceneID, UUIDv4::UUID lineID, UUIDv4::UUID speakerID);
		static void SetLineText(UUIDv4::UUID sceneID, UUIDv4::UUID lineID, const std::string& text);

		static std::unordered_map<UUIDv4::UUID, Scene> scenes;
		static std::unordered_map<UUIDv4::UUID, Character> characters;

		static UUIDv4::UUID CreateID();
}

#endif // !DIALOGUEMANAGER_H

