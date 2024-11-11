// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "observador.h"
#include "enemigo.h"
//#include "publicador.generated.h"  // Este debe ser el �ltimo #include
#include "SpawnerObservador.generated.h"

UCLASS()
class DONKEYKONGSIS457_API ASpawnerObservador : public AActor, public Iobservador
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    ASpawnerObservador();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    virtual void actualizar(Apublicador* publicador);

    UPROPERTY(EditAnywhere, Category = "Spawning")
    TSubclassOf<Aenemigo> EnemyClass;
};