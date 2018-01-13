// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
#include "TankAIController.h"

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

ATank* ATankAIController::GetPlayerTank() const
{	
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());	
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}