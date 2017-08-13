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
    void Elevate(float DegreesPerSecond);
    
private:
    UPROPERTY(editAnywhere, Category = Setup)
    float MaxDegreesPerSecond = 20;
    
    UPROPERTY(editAnywhere, Category = Setup)
    float MaxElevationDegrees = 40;
    
    UPROPERTY(editAnywhere, Category = Setup)
    float MinElevationDegrees = 0; 	
};
