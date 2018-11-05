// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "FPSOBJ01GameMode.h"
#include "FPSOBJ01HUD.h"
#include "FPSOBJ01Character.h"
#include "UObject/ConstructorHelpers.h"

AFPSOBJ01GameMode::AFPSOBJ01GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFPSOBJ01HUD::StaticClass();
}
