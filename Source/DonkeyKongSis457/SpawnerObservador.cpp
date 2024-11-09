// Fill out your copyright notice in the Description page of Project Settings.



#include "SpawnerObservador.h"
#include "enemigo.h"

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
	if (Enemyclass != nullptr)
	{
		UWorld* world = GetWorld();
		if (world)
		{
			FVector SpawnLocation = GetActorLocation() + FVector(FMath::RandRange(-500, 500), FMath::RandRange(-500, 500), 50);
			FRotator SpawnRotation = FRotator::ZeroRotator;
			world->SpawnActor<Aenemigo>(EnemyClass, SpawnLocation, SpawnRotation);
		
			if (NewEnemy)
			{ 
				if (GEngine)
				{
					GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Enemy spawned at location: %s"), *SpawnLocation.ToString()));
				}

			}
		
		}
	}

}

