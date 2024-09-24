// Copyright Epic Games, Inc. All Rights Reserved.

#include "DonkeyKongSis457GameMode.h"
#include "DonkeyKongSis457Character.h"
#include "UObject/ConstructorHelpers.h"
#include "ComponentePlataforma.h"
#include "Kismet/KismetMathLibrary.h"
#include "plataforma.h"
#include "enemigo.h"
#include "muro.h"
#include "muroelectrico.h"
#include "muroladrillo.h"
#include "muro_de_fuego.h"
#include "murohelado.h"
#include <cstdlib> // Necesario para la función rand()
#include <ctime>   // Necesario para la función time()
#include <set>     // Necesario para std::set


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
	FTransform SpawnLocation2;  
    FTransform Spawnlocation3;
    FTransform SpawnLocation4;//muro
    FTransform SpawnLocation5;//muro de fuego
    FTransform SpawnLocation6;//muro electrico
    FTransform SpawnLocation7;//muro helado

    int aumentoenz = 5;
    int incremento = 150;
    int num1 = 0;
    int disminucion = 0;
    int num2 = 90;
	int num3 = 300;
	int num4 = -3450;   
	int num5 = 0;
	int num6 = 0;
	int num7 = 0;

    for (int a = 0; a < 5; a++) {
        if (a % 2 == 0) {
            SpawnLocation2.SetLocation(FVector(1160.0f, 1500.0f, 930.0f+num5));
            SpawnLocation2.SetRotation(FQuat(FRotator(0.0f, 0.0f, 0.0f)));
            SpawnLocation2.SetScale3D(FVector(4.0f, 5.0f, 1.0f));
			

            // Generar el actor Plataforma
            GetWorld()->SpawnActor<Aplataforma>(Aplataforma::StaticClass(), SpawnLocation2);

        }
        else {

            SpawnLocation2.SetLocation(FVector(1160.0f, 1500.0f + num4, 930.0f + num3+num6));
            SpawnLocation2.SetRotation(FQuat(FRotator(0.0f, 0.0f, 0.0f)));
            SpawnLocation2.SetScale3D(FVector(4.0f, 5.0f, 1.0f));
            num6 = num6 + 1120;
            // Generar el actor Plataforma
            GetWorld()->SpawnActor<Aplataforma>(Aplataforma::StaticClass(), SpawnLocation2);
        }
        num5 = num5 + 560;
		
    }

    for (int i = 0; i < 5; i++)
    {
        
            if (i % 2 == 0)
            {
                SpawnLocation.SetLocation(FVector(1160.0f, -210.0f, 430.0f + i * 100.0f * aumentoenz + incremento - disminucion + num2+num1));
                SpawnLocation.SetRotation(FQuat(FRotator(0.0f, 0.0f, -10.0f)));
                SpawnLocation.SetScale3D(FVector(4.0f, 30.0f, 1.0f));
            }
            else
            {
                SpawnLocation.SetLocation(FVector(1160.0f, -210.0f, 580.0f + i * 100.0f * aumentoenz + incremento - disminucion+num7));
                SpawnLocation.SetRotation(FQuat(FRotator(0.0f, 0.0f, 0.0f)));
                SpawnLocation.SetScale3D(FVector(4.0f, 30.0f, 1.0f));
                incremento = incremento + 250;
                disminucion = disminucion + 150;
                num7 = num7 + 20;
            }
			num1 = num1 + 10;
			

            AComponentePlataforma* NewPlatform = GetWorld()->SpawnActor<AComponentePlataforma>(AComponentePlataforma::StaticClass(), SpawnLocation);
            if (NewPlatform)
            {
                componenteplataforma.Add(i + 1, NewPlatform);
            }
            srand(time(nullptr));

            std::set<int> numerosGenerados; // Conjunto para almacenar números generados
            int j = 0;

            while (j < 3) { // Cambiamos la condición para que solo se ejecute 3 veces
                int RandomNumber = rand() % 5 + 1;

                // Verificamos si el número ya ha sido generado
                if (numerosGenerados.find(RandomNumber) == numerosGenerados.end()) {

                    numerosGenerados.insert(RandomNumber); // Añadimos el número al conjunto

                    if (RandomNumber == 1 && i + 1 == 1) {
                        NewPlatform->bShouldMove = true;
                        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Se mueve la plataforma 1"));
                    }
                    else if (RandomNumber == 2 && i + 1 == 2) {
                        NewPlatform->bShouldMove = true;
                        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Se mueve la plataforma 2"));
                    }
                    else if (RandomNumber == 3 && i + 1 == 3) {
                        NewPlatform->bShouldMove = true;
                        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Se mueve la plataforma 3"));
                    }
                    else if (RandomNumber == 4 && i + 1 == 4) {
                        NewPlatform->bShouldMove = true;
                        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Se mueve la plataforma 4"));
                    }
                    else if (RandomNumber == 5 && i + 1 == 5) {
                        NewPlatform->bShouldMove = true;
                        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Se mueve la plataforma 5"));
                    }

                    j++; // Incrementamos el contador solo si el número es nuevo
                }
            }

    }



    //Spaw de muro helado
    SpawnLocation4.SetLocation(FVector(1160.0f, 1500.0f, 1500.0f));
     SpawnLocation4.SetRotation(FQuat(FRotator(90.0f, 90.0f, 0.0f)));
     SpawnLocation4.SetScale3D(FVector(0.05f, 0.05f, 0.05f));
     
     // Generar el actor Plataforma
     GetWorld()->SpawnActor<Amurohelado>(Amurohelado::StaticClass(), SpawnLocation4);

     //Spaw de muro de fuego
     SpawnLocation5.SetLocation(FVector(1160.0f, -1400.0f, 1800.0f));
     SpawnLocation5.SetRotation(FQuat(FRotator(90.0f, 90.0f, 0.0f)));
     SpawnLocation5.SetScale3D(FVector(2.05f, 2.05f, 2.05f));

     // Generar el actor Plataforma
     GetWorld()->SpawnActor<Amuroladrillo>(Amuroladrillo::StaticClass(), SpawnLocation5);


     //Spaw de muro electrico
     SpawnLocation5.SetLocation(FVector(1160.0f, 1000.0f, 2700.0f));
     SpawnLocation5.SetRotation(FQuat(FRotator(90.0f, 90.0f, 0.0f)));
     SpawnLocation5.SetScale3D(FVector(2.05f, 2.05f, 2.05f));

     // Generar el actor Plataforma
     GetWorld()->SpawnActor<Amuro_de_fuego>(Amuro_de_fuego::StaticClass(), SpawnLocation5);

     //Spawn de muro ladrillo
     SpawnLocation6.SetLocation(FVector(1160.0f, 1500.0f, 2100.0f));
     SpawnLocation6.SetRotation(FQuat(FRotator(0.0f,180.0f, 0.0f)));
     SpawnLocation6.SetScale3D(FVector(0.05f, 0.05f, 0.05f));

     // Generar el actor Plataforma
     GetWorld()->SpawnActor<Amuro>(Amuro::StaticClass(), SpawnLocation6);

     SpawnLocation7.SetLocation(FVector(1160.0f, 500.0f, 200.0f));
     SpawnLocation7.SetRotation(FQuat(FRotator(0.0f, 90.0f, 0.0f)));
     SpawnLocation7.SetScale3D(FVector(0.05f, 0.05f, 0.05f));

     // Generar el actor Plataforma
     GetWorld()->SpawnActor<Amuroelectrico>(Amuroelectrico::StaticClass(), SpawnLocation7);
}
void ADonkeyKongSis457GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}
