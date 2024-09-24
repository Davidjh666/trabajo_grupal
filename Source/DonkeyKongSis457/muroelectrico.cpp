// Fill out your copyright notice in the Description page of Project Settings.


#include "muroelectrico.h"

Amuroelectrico::Amuroelectrico()
{  

	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Geometry/Meshes/TemplateFloor.TemplateFloor'"));
	Meshmuro = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Meshmuro->SetStaticMesh(MeshAsset.Object);
	RootComponent = Meshmuro;
}

