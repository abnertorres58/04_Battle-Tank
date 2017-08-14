

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //Must be the last include

class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
    
private:
    ATank* GetControlledTank() const;
	
    virtual void BeginPlay() override;
    
    virtual void Tick(float DeltaTime) override;
	
    //Start the tank moving the barrel so that a shot would hit where
    //the crosshair intersects the world
    void AimTowardsCrosshair();
    //Return an out parameter, true if hit landscape
    bool GetSightRayHitLocation(FVector& OutHitLocation) const;
    
    UPROPERTY(EditAnywhere)
    float CrossHairXLocation = 0.5;
    
    UPROPERTY(EditAnywhere)
    float CrossHairYLocation = 0.3333;
    
    UPROPERTY(EditAnywhere)
    float LineTraceRange = 1000000.0;
    
    bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
    
    bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

};
