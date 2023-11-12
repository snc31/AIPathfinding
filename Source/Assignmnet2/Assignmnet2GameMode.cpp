// Copyright Epic Games, Inc. All Rights Reserved.

#include "Assignmnet2GameMode.h"
#include "Assignmnet2Character.h"
#include "UObject/ConstructorHelpers.h"

AAssignmnet2GameMode::AAssignmnet2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
