#pragma once

#ifndef CHARACTER_H
#define CHARACTER_H

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
	struct Character
	{
		UUIDv4::UUID id;
		std::string name;
	};
}

#endif // !CHARACTER_H