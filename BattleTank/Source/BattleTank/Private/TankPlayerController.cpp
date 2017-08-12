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
    
    FVector HitLocation; //Out Parameter
    if(GetSightRayHitLocation(HitLocation)) //Has a side-effect, is going to line trace
    {
    UE_LOG(LogTemp, Warning, TEXT("HitLocation %s"), *HitLocation.ToString());
    
    
    
    //
        //Tell the controller to aim to this point
    }
}

//Get world location of linetrace trough crosshair, true if it hits the lanscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
    OutHitLocation = FVector(1.0);
    return true;
}


