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

namespace Weaver
{
	class WEAVERLIBRARY_API FileIO
	{
	public:
		FileIO();
		~FileIO();
	};
}

#endif // !FILEIO_H