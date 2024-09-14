// Copyright Epic Games, Inc. All Rights Reserved.

#include "DonkeyKongSis457GameMode.h"
#include "DonkeyKongSis457Character.h"
#include "UObject/ConstructorHelpers.h"

ADonkeyKongSis457GameMode::ADonkeyKongSis457GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
