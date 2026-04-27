#pragma once

#ifndef SCENE_H
#define SCENE_H

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
#include <unordered_map>
#include "uuid_v4.h"
#include "DialogueEntry.h"

namespace StoryStack
{
	struct Scene 
	{
		UUIDv4::UUID id;
		std::string name;
		std::unordered_map<UUIDv4::UUID, StoryStack::DialogueEntry> dialogues;
		std::vector<UUIDv4::UUID> dialogueOrder;
	};
}

#endif // !SCENE_H