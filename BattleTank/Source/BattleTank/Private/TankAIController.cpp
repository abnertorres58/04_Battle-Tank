// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
    
    auto ControlledTank = GetControlledTank();
    
    if(!ControlledTank)
    {
        UE_LOG(LogTemp,Warning,TEXT("AIController not possesing a Tank"));
    }
    else
    {
        UE_LOG(LogTemp,Warning,TEXT("AIController posesing: %s"), *(ControlledTank->GetName()));
    }
}

ATank* ATankAIController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}



