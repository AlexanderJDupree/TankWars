// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI ERROR: NO Player Controller found."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Tank found: %s"), *PlayerTank->GetName());
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ATank* PlayerTank = GetPlayerTank();
	if (PlayerTank)
	{
		// TODO Move towards the player

		// Aim towards the player
		GetControlledTank()->AimtAt(PlayerTank->GetActorLocation());

		// Fire if ready

	}
}

ATank* ATankAIController::GetPlayerTank() const
{	
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());	
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}