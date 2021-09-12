// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickups/ShooterPickup_SpeedBuff.h"
#include "OnlineSubsystemUtils.h"
#include "MyAbilitySystemComponent.h"

AShooterPickup_SpeedBuff::AShooterPickup_SpeedBuff(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

bool AShooterPickup_SpeedBuff::CanBePickedUp(AShooterCharacter* TestPawn) const
{
	// 버프를 먹을수 있는가? (죽지만 않으면?)
	return Super::CanBePickedUp(TestPawn);
}

void AShooterPickup_SpeedBuff::GivePickupTo(AShooterCharacter* Pawn)
{
	Super::GivePickupTo(Pawn);
	if (Pawn)
	{
		//Pawn->AbilitySystemComponent->apply
	}
}
