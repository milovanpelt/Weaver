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

namespace Weaver
{
	struct DialogueEntry
	{
		std::string speaker;
		std::vector<std::string> lines;
	};
}

#endif // !DIALOGUEENTRY_H