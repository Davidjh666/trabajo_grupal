// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DonkeyKongSis457GameMode.generated.h"


class AComponentePlataforma;


UCLASS(minimalapi)
class ADonkeyKongSis457GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ADonkeyKongSis457GameMode();
protected:
	virtual void BeginPlay() override;
public:


	TMap<int32, AComponentePlataforma*> componenteplataforma;
	virtual void Tick(float DeltaTime) override;

	
};



