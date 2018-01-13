// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be last include

/**
 * 
 */
UCLASS()
class TANKWARS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	
	virtual void BeginPlay() override;
	
public:
	
	virtual void Tick(float DeltaTime) override;

	ATank* GetControlledTank() const;

private:
	
	void AimTowardsCrosshair(); 

};
