#include "pch.h"
#include "DialogueManager.h"

namespace Weaver 
{
	std::unordered_map<UUIDv4::UUID, Scene> scenes;
	std::unordered_map<UUIDv4::UUID, Character> characters;

	UUIDv4::UUID CreateID()
	{
		UUIDv4::UUIDGenerator<std::mt19937_64> uuidGenerator;
		return uuidGenerator.getUUID();
	}

	UUIDv4::UUID CreateCharacter(const std::string& newCharacterName)
	{
		// No duplicate character names can exist
		for (const auto& character : characters)
		{
			const std::string& existingCharacterName = character.second.name;
			if (newCharacterName == existingCharacterName)
			{
				std::cout << "[DialogueManager]: Character name already exists: " + newCharacterName + " \n";
				return UUIDv4::UUID();
			}
		}

		Character newCharacter;
		UUIDv4::UUID newCharacterID = CreateID();

		newCharacter.id = newCharacterID;
		newCharacter.name = newCharacterName;

		characters[newCharacterID] = newCharacter;

		std::cout << "[DialogueManager]: Character added: " + newCharacterName + " \n";

		return newCharacterID;
	}

	std::vector<std::string> GetCharacterNames()
	{
		std::vector<std::string> characterNames;
		characterNames.reserve(characters.size());

		for (const auto& character : characters)
		{
			characterNames.push_back(character.second.name);
		}

		return characterNames;
	}

	std::unordered_map<UUIDv4::UUID, Character> GetCharacters()
	{
		return characters;
	}

	UUIDv4::UUID CreateScene(const std::string& newSceneName)
	{
		// No duplicate scene names can exist
		for (const auto& scene : scenes)
		{
			const std::string& existingSceneName = scene.second.name;
			if (newSceneName == existingSceneName)
			{
				std::cout << "[DialogueManager]: Scene name already exists: " + newSceneName + " \n";
				return UUIDv4::UUID();
			}
		}

		Scene newScene;
		UUIDv4::UUID newSceneID = CreateID();

		newScene.id = newSceneID;
		newScene.name = newSceneName;

		scenes[newSceneID] = newScene;

		return newSceneID;
	}

	std::unordered_map<UUIDv4::UUID, Scene> GetScenes()
	{
		return scenes;
	}

	UUIDv4::UUID AddDialogueToCharacter(UUIDv4::UUID sceneID, UUIDv4::UUID speakerID, DialogueTypes type, const std::string& dialogue)
	{
		DialogueEntry newDialogueEntry;
		UUIDv4::UUID newDialogueEntryID = CreateID();

		newDialogueEntry.line = dialogue;
		newDialogueEntry.speaker_id = speakerID;
		newDialogueEntry.line_id = newDialogueEntryID;
		newDialogueEntry.type = type;

		auto sceneIt = scenes.find(sceneID);
		if (sceneIt != scenes.end())
		{
			Scene& scene = sceneIt->second;
			scene.dialogues[newDialogueEntryID] = newDialogueEntry;
			scene.dialogueOrder.push_back(newDialogueEntryID);
		}

		return newDialogueEntryID;
	}

	void SetSpeaker(UUIDv4::UUID sceneID, UUIDv4::UUID lineID, UUIDv4::UUID speakerID)
	{
	}

	void SetLineText(UUIDv4::UUID sceneID, UUIDv4::UUID lineID, const std::string& text)
	{
		auto sceneIt = scenes.find(sceneID);
		if (sceneIt != scenes.end())
		{
			Scene& scene = sceneIt->second;

			auto dialogueIt = scene.dialogues.find(lineID);
			if (dialogueIt != scene.dialogues.end())
			{
				DialogueEntry& entry = dialogueIt->second;
				entry.line = text;
			}
		}
	}
}
