#pragma once

#ifndef DIALOGUEENTRY_H
#define DIALOGUEENTRY_H

#ifdef _WIN32
#ifdef WEAVERLIBRARY_EXPORTS
#define WEAVERLIBRARY_API __declspec(dllexport)
#else
#define WEAVERLIBRARY_API __declspec(dllimport)
#endif
#else
#define WEAVERLIBRARY_API
#endif

#include <pch.h>
#include <uuid_v4.h>

namespace Weaver
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