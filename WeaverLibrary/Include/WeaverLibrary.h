#pragma once
#ifndef WEAVERLIBRARY_H
#define	WEAVERLIBRARY_H

#ifdef WEAVERLIBRARY_EXPORTS
#define WEAVERLIBRARY_API __declspec(dllexport)
#else
#define WEAVERLIBRARY_API __declspec(dllimport)
#endif

#include "pch.h"
#include "FileIO.h"




#endif // !WEAVERLIBRARY_H