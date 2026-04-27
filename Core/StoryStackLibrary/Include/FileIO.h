#pragma once

#ifndef FILEIO_H
#define FILEIO_H

#ifdef _WIN32
#ifdef STORYSTACKLIBRARY_EXPORTS
#define STORYSTACKLIBRARY_API __declspec(dllexport)
#else
#define STORYSTACKLIBRARY_API __declspec(dllimport)
#endif
#else
#define STORYSTACKLIBRARY_API
#endif

#include "Scene.h"
#include "Character.h"

namespace StoryStack
{
	class STORYSTACKLIBRARY_API FileIO
	{
	public:
		FileIO();
		~FileIO();

		static bool SaveDialogueToJSON(const std::string& filename, const std::unordered_map<UUIDv4::UUID, Character>& characters, const std::unordered_map<UUIDv4::UUID, Scene>& scenes);
		//static const std::vector<DialogueEntry> ReadDialogueFromJSON(const std::string& filename);
	};
}

#endif // !FILEIO_H