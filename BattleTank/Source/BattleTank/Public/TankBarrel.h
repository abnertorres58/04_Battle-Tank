// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS( meta=(BlueprintSpawnableComponent), hidecategories ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
    
public:
    //-1 is a max dounward movement, +1 max up movement
    void Elevate(float RelativeSpeed);
    
private:
    UPROPERTY(editAnywhere, Category = Setup)
    float MaxDegreesPerSecond = 20;
    
    UPROPERTY(editAnywhere, Category = Setup)
    float MaxElevationDegrees = 40;
    
    UPROPERTY(editAnywhere, Category = Setup)
    float MinElevationDegrees = 0; 	
};
