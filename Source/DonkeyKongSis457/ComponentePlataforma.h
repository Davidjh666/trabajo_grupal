#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ComponentePlataforma.generated.h"

UCLASS()
class DONKEYKONGSIS457_API AComponentePlataforma : public AActor
{
    GENERATED_BODY()

public:
    AComponentePlataforma();

protected:
    UStaticMeshComponent* MeshComponentePlataforma;
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;
    void MoverActor(float DeltaTime);

    float MovimientoY = 0.0f;
    float Velocidad = 100.0f;
    bool Direccion = true;
    bool bShouldMove = false;
};