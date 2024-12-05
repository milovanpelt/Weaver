// Copyright Epic Games, Inc. All Rights Reserved.

#include "WeaverExampleGameGameMode.h"
#include "WeaverExampleGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWeaverExampleGameGameMode::AWeaverExampleGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
