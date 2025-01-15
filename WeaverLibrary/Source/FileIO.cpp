#include "pch.h"
#include "FileIO.h"
#include <fstream>

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
		// Create Json object
		nlohmann::json dialogueData;

		for (const auto entry : dialogues)
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
}
