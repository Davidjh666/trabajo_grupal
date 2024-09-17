#include "ComponentePlataforma.h"

// Sets default values
AComponentePlataforma::AComponentePlataforma()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));
	MeshComponentePlataforma = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	MeshComponentePlataforma->SetStaticMesh(MeshAsset.Object);
	RootComponent = MeshComponentePlataforma;
}

// Called when the game starts or when spawned
void AComponentePlataforma::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AComponentePlataforma::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoverActor(DeltaTime);
}


void AComponentePlataforma::MoverActor(float DeltaTime)
{
	if (!bShouldMove)
		return;
	FVector NuevaPosicion = GetActorLocation();

	if (Direccion)
	{
		MovimientoY += Velocidad * DeltaTime;
		if (MovimientoY >= 500.0f)
		{
			Direccion = false;
		}
	}
	else
	{
		MovimientoY -= Velocidad * DeltaTime;
		if (MovimientoY <= -500.0f)
		{
			Direccion = true;
		}
	}

	NuevaPosicion.Y = MovimientoY;
	SetActorLocation(NuevaPosicion);
}