#include <pch.h>
#include "FileIO.h"
#include <fstream>
#include "json.hpp"

namespace Weaver
{
	Weaver::FileIO::FileIO()
	{
	}

	Weaver::FileIO::~FileIO()
	{
	}

	bool FileIO::SaveDialogueToJSON(const std::string& filename, const std::unordered_map<UUIDv4::UUID, Character>& characters, const std::unordered_map<UUIDv4::UUID, Scene>& scenes)
	{
		nlohmann::json dialogueData;

		for (const auto& character : characters)
		{
			std::string stringedCharacterID = static_cast<std::ostringstream*> (&(std::ostringstream() << character.second.id))->str();
			std::string stringedCharacterName = static_cast<std::ostringstream*> (&(std::ostringstream() << character.second.name))->str();
			dialogueData["characters"] = { stringedCharacterID, stringedCharacterName };
		}

		for (const auto& scene : scenes)
		{
			std::string stringedSceneID = static_cast<std::ostringstream*> (&(std::ostringstream() << scene.second.id))->str();
			std::string stringedSceneName = static_cast<std::ostringstream*> (&(std::ostringstream() << scene.second.name))->str();

			dialogueData["scenes"] = { stringedSceneID, stringedSceneName };
		}

		std::ofstream output_file(filename);
		if (!output_file.is_open())
		{
			std::cout << filename << " could not be opened";
			return false;
		}
		
		output_file << dialogueData.dump(2);
		output_file.close();

		return true;
	}

	//const std::vector<DialogueEntry> FileIO::ReadDialogueFromJSON(const std::string& filename)
	//{
	//	std::vector<DialogueEntry> dialogueEntries;

	//	nlohmann::json dialogueJSONData;

	//	std::ifstream input_file(filename);
	//	if (!input_file.is_open())
	//	{
	//		std::cout << "[FileIO]: " << filename << " could not be opened" << "\n\n";
	//	}

	//	dialogueJSONData = nlohmann::json::parse(input_file);

	//	/*for (auto& entry : dialogueJSONData.items())
	//	{
	//		DialogueEntry dialogueEntry;

	//		dialogueEntry.speaker = entry.key();
	//		dialogueEntry.lines = entry.value();

	//		dialogueEntries.push_back(dialogueEntry);
	//	}*/

	//	std::cout << "[FileIO]: " << "Read " << filename << "\n";
	//	return dialogueEntries;
	//}
}
