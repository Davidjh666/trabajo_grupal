// Copyright Epic Games, Inc. All Rights Reserved.

#include "DonkeyKongSis457GameMode.h"
#include "DonkeyKongSis457Character.h"
#include "UObject/ConstructorHelpers.h"
#include "ComponentePlataforma.h"
#include "Kismet/KismetMathLibrary.h"

ADonkeyKongSis457GameMode::ADonkeyKongSis457GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}



void ADonkeyKongSis457GameMode::BeginPlay()
{
	Super::BeginPlay();
	FTransform SpawnLocation;
	int aumentoenz = 5;
	int incremento = 150;
	int num1 = 1;
	int disminucion = 0;

	int num2 = 250;

	for (int i = 0; i < 5; i++)
	{
		for (int num = 1; num < 5; num++)
		if (i % 2 == 0) {
			SpawnLocation.SetLocation(FVector(1160.0f, -210.0f, 310.0f + i * 100.0f * aumentoenz + incremento-disminucion+num2));
			SpawnLocation.SetRotation(FQuat(FRotator(0.0f, 0.0f, -10.0f)));
			SpawnLocation.SetScale3D(FVector(4.0f, 30.0f, 1.0f));
	
		}
		else {
			SpawnLocation.SetLocation(FVector(1160.0f, -210.0f, 460.0f + i * 100.0f * aumentoenz + incremento-disminucion));
			SpawnLocation.SetRotation(FQuat(FRotator(0.0f, 0.0f, 0.0f)));
			SpawnLocation.SetScale3D(FVector(4.0f, 30.0f, 1.0f));
			incremento = incremento + 250;
			disminucion = disminucion + 150;
		}
	
		AComponentePlataforma* NewPlatform = GetWorld()->SpawnActor<AComponentePlataforma>(AComponentePlataforma::StaticClass(), SpawnLocation);
		if (NewPlatform)
		{
			componenteplataforma.Add(i + 1, NewPlatform); // Agrega la nueva plataforma al TMap
		}
	}
	
}
void ADonkeyKongSis457GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Verifica si el tercer elemento existe en el TMap
	if (AComponentePlataforma** FoundPlatform = componenteplataforma.Find(3)) // Accede al tercer elemento (clave 3)
	{
		if (*FoundPlatform)
		{
			// Llama al método MoverActor del tercer elemento
			(*FoundPlatform)->MoverActor(DeltaTime); // Usa tu método MoverActor aquí
		}
	}
}
