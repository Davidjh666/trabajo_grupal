// Fill out your copyright notice in the Description page of Project Settings.


#include "muro.h"

// Sets default values
Amuro::Amuro()
{
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Geometry/Meshes/TemplateFloor.TemplateFloor'"));
	Meshmuro = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	Meshmuro->SetStaticMesh(MeshAsset.Object);
	RootComponent = Meshmuro;
}

void Amuro::movermuro()
{
}

// Called when the game starts or when spawned
void Amuro::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Amuro::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

