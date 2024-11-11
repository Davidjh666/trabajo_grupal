// Fill out your copyright notice in the Description page of Project Settings.



#include "SpawnerObservador.h"
#include "enemigo.h"
#include "publicador.h"

ASpawnerObservador::ASpawnerObservador()
{
	PrimaryActorTick.bCanEverTick = true;

	// Initialize EnemyClass

}

// Called when the game starts or when spawned
void ASpawnerObservador::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnerObservador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawnerObservador::actualizar(Apublicador* publicador)
{
	if (EnemyClass != nullptr)
	{
		UWorld* world = GetWorld();
		if (world)
		{
			// Definir la ubicación y rotación del enemigo
			FVector SpawnLocation = GetActorLocation() + FVector(FMath::RandRange(-500, 500), FMath::RandRange(-500, 500), 50);
			FRotator SpawnRotation = FRotator::ZeroRotator;

			// Intentar crear el enemigo
			Aenemigo* NewEnemy = world->SpawnActor<Aenemigo>(EnemyClass, SpawnLocation, SpawnRotation);

			// Si se crea exitosamente, mostrar mensaje en pantalla y notificar a otros observadores
			if (NewEnemy)
			{ 
				// Mensaje en pantalla 
				 if (GEngine)
				 { 
					 GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Enemy spawned at location: %s"), *SpawnLocation.ToString())); 
				 } 
				 // Mensaje en el log 
				 //UE_LOG(LogTemp, Log, TEXT("Enemy spawned at location: %s"), *SpawnLocation.ToString());
			}
		}
	}
}

