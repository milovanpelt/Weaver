#include "pch.h"
#include "DialogueManager.h"

namespace Weaver
{
	std::unordered_map<UUIDv4::UUID, Scene> DialogueManager::scenes;
	std::unordered_map<UUIDv4::UUID, Character> DialogueManager::characters;
}

namespace Weaver
{
	UUIDv4::UUID DialogueManager::AddCharacter(const std::string& newCharacterName)
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

		return newCharacterID;
	}

	std::vector<std::string> DialogueManager::GetCharacterNames()
	{
		std::vector<std::string> characterNames;
		characterNames.reserve(DialogueManager::characters.size());

		for (const auto& character : characters)
		{
			characterNames.push_back(character.second.name);
		}

		return characterNames;
	}

	UUIDv4::UUID DialogueManager::CreateScene(const std::string& newSceneName)
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

	UUIDv4::UUID Weaver::DialogueManager::CreateDialogueEntry(UUIDv4::UUID sceneID, Weaver::DialogueTypes type)
	{
		DialogueEntry newDialogueEntry;
		UUIDv4::UUID newDialogueEntryID = CreateID();

		newDialogueEntry.line_id = newDialogueEntryID;
		newDialogueEntry.type = type;

		auto sceneIt = scenes.find(sceneID);
		if (sceneIt != scenes.end())
		{
			Scene& scene = sceneIt->second;
			scene.dialogues[newDialogueEntryID] = newDialogueEntry;
			scene.dialogueOrder.push_back(sceneID);
		}
		
		return newDialogueEntryID;
	}

	void Weaver::DialogueManager::SetSpeaker(UUIDv4::UUID sceneID, UUIDv4::UUID lineID, UUIDv4::UUID speakerID)
	{
	}

	void Weaver::DialogueManager::SetLineText(UUIDv4::UUID sceneID, UUIDv4::UUID lineID, const std::string& text)
	{
	}

	UUIDv4::UUID Weaver::DialogueManager::CreateID()
	{
		UUIDv4::UUIDGenerator<std::mt19937_64> uuidGenerator;
		return uuidGenerator.getUUID();
	}
}
