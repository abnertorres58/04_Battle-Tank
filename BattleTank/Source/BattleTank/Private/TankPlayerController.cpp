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
    //UE_LOG(LogTemp, Warning, TEXT("HitLocation %s"), *HitLocation.ToString());
    
    //
        //TODO Tell the controller to aim to this point
    }
}

//Get world location of linetrace trough crosshair, true if it hits the lanscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
    //Find the crosshair position in pixel coordinates
    int32 ViewportSizeX, ViewportSizeY;
    GetViewportSize(ViewportSizeX, ViewportSizeY);
    
    auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation,
                                    ViewportSizeY * CrossHairYLocation);
   
    //"De-project" the screen projection of the crosshair to a world direction
    //Line-trace along that look direction, and see what we hit (up to maximum range)
    return true;
}


