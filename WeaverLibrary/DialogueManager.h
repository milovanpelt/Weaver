#pragma once

#include <unordered_map>
#include "Character.h"
#include "Scene.h"
#include "DialogueEntry.h"


class DialogueManager
{
public:
	static UUIDv4::UUID AddCharacter(const std::string& name);
	static std::vector<std::string> GetCharacterNames();
	static UUIDv4::UUID CreateScene(const std::string& name);
	static UUIDv4::UUID CreateDialogueEntry(UUIDv4::UUID sceneID, Weaver::DialogueTypes type);
	static void SetSpeaker(UUIDv4::UUID sceneID, UUIDv4::UUID lineID, UUIDv4::UUID speakerID);
	static void SetLineText(UUIDv4::UUID sceneID, UUIDv4::UUID lineID, const std::string& text);
private:
	static std::unordered_map<UUIDv4::UUID, Weaver::Scene> scenes;
	static std::unordered_map<UUIDv4::UUID, Weaver::Character> characters;
};

