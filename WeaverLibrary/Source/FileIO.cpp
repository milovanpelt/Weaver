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

	bool FileIO::SaveDialogueToJSON(const std::string& filename, const std::vector<DialogueEntry>& dialogues)
	{
		nlohmann::json dialogueData;

		for (const auto& entry : dialogues)
		{
			dialogueData[entry.speaker] = entry.lines;
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

	const std::vector<DialogueEntry> FileIO::ReadDialogueFromJSON(const std::string& filename)
	{
		std::vector<DialogueEntry> dialogueEntries;

		nlohmann::json dialogueJSONData;

		std::ifstream input_file(filename);
		if (!input_file.is_open())
		{
			std::cout << "[FileIO]: " << filename << " could not be opened" << "\n\n";
		}

		dialogueJSONData = nlohmann::json::parse(input_file);

		for (auto& entry : dialogueJSONData.items())
		{
			DialogueEntry dialogueEntry;

			dialogueEntry.speaker = entry.key();
			dialogueEntry.lines = entry.value();

			dialogueEntries.push_back(dialogueEntry);
		}

		std::cout << "[FileIO]: " << "Read " << filename << "\n";
		return dialogueEntries;
	}
}
