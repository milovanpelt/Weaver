#pragma once

#ifndef SCENE_H
#define SCENE_H

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
#include <unordered_map>
#include "uuid_v4.h"
#include "DialogueEntry.h"

namespace Weaver
{
	struct Scene 
	{
		UUIDv4::UUID id;
		std::string name;
		std::unordered_map<UUIDv4::UUID, Weaver::DialogueEntry> dialogues;
		std::vector<UUIDv4::UUID> dialogueOrder;
	};
}

#endif // !SCENE_H