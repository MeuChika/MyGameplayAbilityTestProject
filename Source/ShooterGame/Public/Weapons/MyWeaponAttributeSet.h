// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "MyWeaponAttributeSet.generated.h"

// Uses macros from AttributeSet.h
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)
/**
 * 
 */
UCLASS()
class SHOOTERGAME_API UMyWeaponAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	UMyWeaponAttributeSet();
	// AttributeSet Overrides
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	public:
	
	//Hitpoints. Self-explanatory.
	UPROPERTY(Category = "WeaponAttributes", EditAnywhere, BlueprintReadWrite, ReplicatedUsing = OnRep_Damage)
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(UMyWeaponAttributeSet, Damage)

	UPROPERTY(Category = "WeaponAttributes", EditAnywhere, BlueprintReadWrite, ReplicatedUsing = OnRep_ClipSize)
	FGameplayAttributeData ClipSize;
	ATTRIBUTE_ACCESSORS(UMyWeaponAttributeSet, ClipSize)
	
	UPROPERTY(Category = "WeaponAttributes", EditAnywhere, BlueprintReadWrite, ReplicatedUsing = OnRep_AmmoInClip)
	FGameplayAttributeData AmmoInClip;
	ATTRIBUTE_ACCESSORS(UMyWeaponAttributeSet, AmmoInClip)

	UPROPERTY(Category = "WeaponAttributes", EditAnywhere, BlueprintReadWrite, ReplicatedUsing = OnRep_TotalAmmo)
	FGameplayAttributeData TotalAmmo;
	ATTRIBUTE_ACCESSORS(UMyWeaponAttributeSet, TotalAmmo)

	UPROPERTY(Category = "WeaponAttributes", EditAnywhere, BlueprintReadWrite, ReplicatedUsing = OnRep_TimeBetweenShots)
	FGameplayAttributeData TimeBetweenShots;
	ATTRIBUTE_ACCESSORS(UMyWeaponAttributeSet, TimeBetweenShots)

	UPROPERTY(Category = "WeaponAttributes", EditAnywhere, BlueprintReadWrite, ReplicatedUsing = OnRep_WeaponRange)
	FGameplayAttributeData WeaponRange;
	ATTRIBUTE_ACCESSORS(UMyWeaponAttributeSet, WeaponRange)
	
	protected:
	UFUNCTION()
	virtual void OnRep_Damage(const FGameplayAttributeData& OldDamage);

	UFUNCTION()
	virtual void OnRep_ClipSize(const FGameplayAttributeData& OldClipSize);
	
	UFUNCTION()
	virtual void OnRep_AmmoInClip(const FGameplayAttributeData& OldAmmo);

	UFUNCTION()
	virtual void OnRep_TotalAmmo(const FGameplayAttributeData& OldAmmo);
	
	UFUNCTION()
	virtual void OnRep_TimeBetweenShots(const FGameplayAttributeData& OldTimeBetweenShots);

	UFUNCTION()
	virtual void OnRep_WeaponRange(const FGameplayAttributeData& OldRange);
	
};
