// Fill out your copyright notice in the Description page of Project Settings.


#include "muro_de_fuego.h"


Amuro_de_fuego::Amuro_de_fuego()
{
	PrimaryActorTick.bCanEverTick = true;

	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));
	Meshmuro_de_fuego = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	Meshmuro_de_fuego->SetStaticMesh(MeshAsset.Object);
	RootComponent = Meshmuro_de_fuego;





}

