#include "pch.h"
#include "DialogueManager.h"

UUIDv4::UUID Weaver::DialogueManager::AddCharacter(const std::string& newCharacterName)
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
	
	Weaver::Character newCharacter;
	UUIDv4::UUID newCharacterID = CreateID();
	
	newCharacter.id = newCharacterID;
	newCharacter.name = newCharacterName;

	characters[newCharacterID] = newCharacter;

	return newCharacterID;
}

std::vector<std::string> Weaver::DialogueManager::GetCharacterNames()
{
	std::vector<std::string> characterNames;
	characterNames.reserve(characters.size());
	
	for (const auto& c : characters)
	{
		characterNames.push_back(c.second.name);
	}

	return characterNames;
}

UUIDv4::UUID Weaver::DialogueManager::CreateScene(const std::string& newSceneName)
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

	Weaver::Scene newScene;
	UUIDv4::UUID newSceneID = CreateID();

	newScene.id = newSceneID;
	newScene.name = newSceneName;

	scenes[newSceneID] = newScene;

	return newSceneID;
}

UUIDv4::UUID Weaver::DialogueManager::CreateDialogueEntry(UUIDv4::UUID sceneID, Weaver::DialogueTypes type)
{
	return UUIDv4::UUID();
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
