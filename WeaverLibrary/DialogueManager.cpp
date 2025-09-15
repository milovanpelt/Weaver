#include "pch.h"
#include "DialogueManager.h"

UUIDv4::UUID Weaver::DialogueManager::AddCharacter(const std::string& name)
{
	// No duplicate character names can exist
	for (const auto& c : characters)
	{
		if (name == c.second.name)
		{
			std::cout << "[DialogueManager]: Character name already exists: " + name + " \n";
			return UUIDv4::UUID();
		}
	}
	
	Weaver::Character newCharacter;
	UUIDv4::UUID newCharacterID = CreateID();
	
	newCharacter.id = newCharacterID;
	newCharacter.name = name;

	characters[newCharacterID] = newCharacter;
	return newCharacterID;
}

std::vector<std::string> Weaver::DialogueManager::GetCharacterNames()
{
	return std::vector<std::string>();
}

UUIDv4::UUID Weaver::DialogueManager::CreateScene(const std::string& name)
{
	return UUIDv4::UUID();
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
