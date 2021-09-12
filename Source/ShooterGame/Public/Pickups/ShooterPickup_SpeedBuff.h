// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickups/ShooterPickup.h"
#include "ShooterPickup_SpeedBuff.generated.h"


UCLASS()
class SHOOTERGAME_API AShooterPickup_SpeedBuff : public AShooterPickup
{
	GENERATED_UCLASS_BODY()
	
	/** check if pawn can use this pickup */
	virtual bool CanBePickedUp(AShooterCharacter* TestPawn) const override;

	protected:
	
	/** give pickup */
	virtual void GivePickupTo(AShooterCharacter* Pawn) override;
};
