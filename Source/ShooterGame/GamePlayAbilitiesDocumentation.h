#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"

UENUM(BlueprintType)
enum class AbilityInput : uint8
{
	None		UMETA(DisplayName = "None"),
	Confirm		UMETA(DisplayName = "Confirm"),
	Cancel		UMETA(DisplayName = "Cancel"),
	UseAbility1 UMETA(DisplayName = "Use Spell 1"), 
	UseAbility2 UMETA(DisplayName = "Use Spell 2"), 
	UseAbility3 UMETA(DisplayName = "Use Spell 3"),
	UseAbility4 UMETA(DisplayName = "Use Spell 4"),
	WeaponAbility UMETA(DisplayName = "Use Weapon"),
	Jump		UMETA(DisplayName = "Jump"),
	Sprint		UMETA(DisplayName = "Sprint")
};
