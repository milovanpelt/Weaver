#pragma once

#ifndef FILEIO_H
#define FILEIO_H

#ifdef _WIN32
#ifdef WEAVERLIBRARY_EXPORTS
#define WEAVERLIBRARY_API __declspec(dllexport)
#else
#define WEAVERLIBRARY_API __declspec(dllimport)
#endif
#else
#define WEAVERLIBRARY_API
#endif

#include "json.hpp"
#include <iostream>
#include <vector>
#include "DialogueEntry.h"

namespace Weaver
{
	class WEAVERLIBRARY_API FileIO
	{
	public:
		FileIO();
		~FileIO();

		static bool SaveDialogueToJSON(const std::string& filename, const std::vector<DialogueEntry>& dialogues);
	};
}

#endif // !FILEIO_H