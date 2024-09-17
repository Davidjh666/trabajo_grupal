// Fill out your copyright notice in the Description page of Project Settings.


#include "plataforma.h"

// Sets default values
Aplataforma::Aplataforma()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));
	MeshPlataforma = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	MeshPlataforma->SetStaticMesh(MeshAsset.Object);
	RootComponent = MeshPlataforma;
}

// Called when the game starts or when spawned
void Aplataforma::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Aplataforma::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

