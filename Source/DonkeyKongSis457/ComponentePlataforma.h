#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ComponentePlataforma.generated.h"

UCLASS()
class DONKEYKONGSIS457_API AComponentePlataforma : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AComponentePlataforma();

protected:
	UStaticMeshComponent* MeshComponentePlataforma;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void MoverActor(float DeltaTime); // Declaración de la función

public:
	float MovimientoY = 0.0f;
	float Velocidad = 100.0f;
	bool Direccion = true;
};
