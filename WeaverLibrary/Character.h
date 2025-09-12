#pragma once

#ifndef CHARACTER_H
#define CHARACTER_H

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
	struct Character
	{
		UUIDv4::UUID id;
		std::string name;
	};
}

#endif // !CHARACTER_H