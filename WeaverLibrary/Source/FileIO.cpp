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
        if (characters.size() == 0 || scenes.size() == 0)
        {
            return false;
        }

        nlohmann::json weaverJsonData = nlohmann::json::object();

		for (const auto& character : characters)
		{
			std::string stringedCharacterID = character.second.id.str();
			std::string characterName = character.second.name;
			weaverJsonData["characters"].push_back({
				{ "id", stringedCharacterID },
				{ "name", characterName }
			});
		}

		for (const auto& scene : scenes)
		{
			std::string stringedSceneID = scene.second.id.str();
			std::string sceneName = scene.second.name;

            nlohmann::json sceneJson;
            sceneJson["id"] = stringedSceneID;
            sceneJson["name"] = sceneName;

            nlohmann::json dialogueJson = nlohmann::json::array();
			nlohmann::json dialogueOrderJson = nlohmann::json::array();

            if (scene.second.dialogues.size() > 0){
                for (const auto& dialogue : scene.second.dialogues)
                {
                    std::string stringedLineID = dialogue.second.line_id.str();
                    std::string stringedSpeakerID = dialogue.second.speaker_id.str();
                    std::string line = dialogue.second.line;

					dialogueJson.push_back({
						{"line_id", stringedLineID},
						{"speaker_id", stringedSpeakerID},
						{"line", line}
					});
                }

                sceneJson["dialogues"] = dialogueJson;

				for (const auto& order : scene.second.dialogueOrder)
				{
					std::string stringedID = order.str();

					dialogueOrderJson.push_back({
						{"line_id", stringedID}
					});
				}

				sceneJson["dialogueOrder"] = dialogueOrderJson;

				weaverJsonData["scenes"].push_back(sceneJson);
            }
		}

		std::ofstream output_file(filename);
		if (!output_file.is_open())
		{
            std::cout << filename << " could not be opened" << std::endl;
			return false;
		}
		
		output_file << weaverJsonData.dump(2);
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
