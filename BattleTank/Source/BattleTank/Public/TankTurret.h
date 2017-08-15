// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta=(BlueprintSpawnableComponent), hidecategories ("Collision"))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
    
    //-1 is a max dounward movement, +1 max up movement
    void Rotate(float RelativeSpeed);
	
private:
    UPROPERTY(editAnywhere, Category = Setup)
    float MaxDegreesPerSecond = 25;

};
