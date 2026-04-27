#pragma once

#ifndef DIALOGUEENTRY_H
#define DIALOGUEENTRY_H

#ifdef _WIN32
#ifdef STORYSTACKLIBRARY_EXPORTS
#define STORYSTACKLIBRARY_API __declspec(dllexport)
#else
#define STORYSTACKLIBRARY_API __declspec(dllimport)
#endif
#else
#define STORYSTACKLIBRARY_API
#endif

#include <pch.h>
#include "uuid_v4.h"

namespace StoryStack
{
	enum class DialogueTypes
	{
		Dialogue,
		Choice,
		Reply
	};

	struct DialogueEntry
	{
		UUIDv4::UUID line_id;
		UUIDv4::UUID speaker_id;
		DialogueTypes type;
		std::string line;
	};
}

#endif // !DIALOGUEENTRY_H