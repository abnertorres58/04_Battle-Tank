// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//Fordward Declaration
class UTankBarrel;

//Holds barrel's properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
    
    void SetBarrelReference(UTankBarrel* BarrelToSet);
    
    //TODO add setTurrentReference
    
    void AimAt(FVector HitLocation, float LaunchSpeed);
    
private:
    UTankBarrel* Barrel = nullptr;
		
    void MoveBarrelTowards(FVector AimDirection);
	
};
