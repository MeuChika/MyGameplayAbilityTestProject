// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/MyWeaponAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"

UMyWeaponAttributeSet::UMyWeaponAttributeSet()
{
}

void UMyWeaponAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY( UMyWeaponAttributeSet, Damage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY( UMyWeaponAttributeSet, ClipSize, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY( UMyWeaponAttributeSet, AmmoInClip, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY( UMyWeaponAttributeSet, TotalAmmo, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY( UMyWeaponAttributeSet, TimeBetweenShots, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY( UMyWeaponAttributeSet, WeaponRange, COND_None, REPNOTIFY_Always);
	   
}

void UMyWeaponAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
}

void UMyWeaponAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

void UMyWeaponAttributeSet::OnRep_Damage(const FGameplayAttributeData& OldDamage)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyWeaponAttributeSet,Damage,OldDamage);
}

void UMyWeaponAttributeSet::OnRep_ClipSize(const FGameplayAttributeData& OldClipSize)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyWeaponAttributeSet,ClipSize,OldClipSize);
}

void UMyWeaponAttributeSet::OnRep_AmmoInClip(const FGameplayAttributeData& OldAmmo)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyWeaponAttributeSet,AmmoInClip,OldAmmo);
}

void UMyWeaponAttributeSet::OnRep_TotalAmmo(const FGameplayAttributeData& OldAmmo)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyWeaponAttributeSet,TotalAmmo,OldAmmo);
}

void UMyWeaponAttributeSet::OnRep_TimeBetweenShots(const FGameplayAttributeData& OldTimeBetweenShots)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyWeaponAttributeSet,TimeBetweenShots,OldTimeBetweenShots);
}

void UMyWeaponAttributeSet::OnRep_WeaponRange(const FGameplayAttributeData& OldRange)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyWeaponAttributeSet,WeaponRange,OldRange);
}
