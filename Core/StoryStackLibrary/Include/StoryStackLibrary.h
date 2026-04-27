#pragma once
#ifndef STORYSTACKLIBRARY_H
#define	STORYSTACKLIBRARY_H

#ifdef STORYSTACKLIBRARY_EXPORTS
#define STORYSTACKLIBRARY_API __declspec(dllexport)
#else
#define STORYSTACKLIBRARY_API __declspec(dllimport)
#endif

#include <pch.h>
#include "FileIO.h"

#include "DialogueManager.h"




#endif // !STORYSTACKLIBRARY_H