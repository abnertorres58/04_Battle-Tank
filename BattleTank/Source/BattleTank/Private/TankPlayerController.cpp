// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();
    
    auto ControlledTank = GetControlledTank();
    
    if(!ControlledTank)
    {
        UE_LOG(LogTemp,Warning,TEXT("PlayController not possesing a Tank"));
    }
    else
    {
        UE_LOG(LogTemp,Warning,TEXT("Player Controller posesing: %s"), *(ControlledTank->GetName()));
    }
}


//Tick
void ATankPlayerController::Tick(float DeltaTime)
{
    //Super
    Super::Tick(DeltaTime);
    
    //UE_LOG(LogTemp, Warning, TEXT("Player Controller ticking"))
    
    AimTowardsCrosshair();
    
}

ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
    if(!GetControlledTank()) {return;}
    
    //Get world location if linetrace trough crosshair
    //If it hits the lanscape
        //Tell the controller to aim to this point
}


