// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/GA_RifleFire.h"
#include "ShooterWeapon.h"
#include "AbilitySystemComponent.h"

UGA_RifleFire::UGA_RifleFire()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	FGameplayTag Ability1Tag = FGameplayTag::RequestGameplayTag(FName("Gun.Fire"));
	AbilityTags.AddTag(Ability1Tag);
	ActivationOwnedTags.AddTag(Ability1Tag);
	//AbilityInputID = AbilityInput::;
}

void UGA_RifleFire::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

void UGA_RifleFire::InputReleased(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo)
{
	Super::InputReleased(Handle, ActorInfo, ActivationInfo);
}

void UGA_RifleFire::CancelAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateCancelAbility)
{
	Super::CancelAbility(Handle, ActorInfo, ActivationInfo, bReplicateCancelAbility);
}

void UGA_RifleFire::ProcessInstantHit(const FHitResult& Impact, const FVector& Origin, const FVector& ShootDir,	int32 RandomSeed, float ReticleSpread)
{
	if (GetAvatarActorFromActorInfo() && GetAvatarActorFromActorInfo()->GetLocalRole() == ROLE_AutonomousProxy && GetAvatarActorFromActorInfo()->GetNetMode() == NM_Client)
	{
		// // if we're a client and we've hit something that is being controlled by the server
		// if (Impact.GetActor() && Impact.GetActor()->GetRemoteRole() == ROLE_Authority)
		// {
		// 	// notify the server of the hit
		// 	ServerNotifyHit(Impact, ShootDir, RandomSeed, ReticleSpread);
		// }
		// else if (Impact.GetActor() == NULL)
		// {
		// 	if (Impact.bBlockingHit)
		// 	{
		// 		// notify the server of the hit
		// 		ServerNotifyHit(Impact, ShootDir, RandomSeed, ReticleSpread);
		// 	}
		// 	else
		// 	{
		// 		// notify server of the miss
		// 		ServerNotifyMiss(ShootDir, RandomSeed, ReticleSpread);
		// 	}
		// }
	}
}

void UGA_RifleFire::FireWeapon()
{
	AShooterWeapon* TempWeapon = Cast<AShooterWeapon>(GetAvatarActorFromActorInfo());
	if (!TempWeapon)
	{
		EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
		return;
	}
	
	const int32 RandomSeed = FMath::Rand();
	FRandomStream WeaponRandomStream(RandomSeed);
	const float CurrentSpread = TempWeapon->GetCurrentSpread();
	const float ConeHalfAngle = FMath::DegreesToRadians(CurrentSpread * 0.5f);

	const FVector AimDir = TempWeapon->GetAdjustedAim();
	const FVector StartTrace = TempWeapon->GetCameraDamageStartLocation(AimDir);
	const FVector ShootDir = WeaponRandomStream.VRandCone(AimDir, ConeHalfAngle, ConeHalfAngle);
	const FVector EndTrace = StartTrace + ShootDir * TempWeapon->GetWeaponRange();
	
	const FHitResult Impact = WeaponTrace(StartTrace, EndTrace);
	ProcessInstantHit(Impact, StartTrace, ShootDir, RandomSeed, CurrentSpread);
	
	TempWeapon->SetCurrentFiringSpread(FMath::Min(TempWeapon->GetInstantConfig().FiringSpreadMax, TempWeapon->GetCurrentFiringSpread() + TempWeapon->GetInstantConfig().FiringSpreadIncrement));
}

FHitResult UGA_RifleFire::WeaponTrace(const FVector& StartTrace, const FVector& EndTrace) const
{

	// Perform trace to retrieve hit info
	FCollisionQueryParams TraceParams(SCENE_QUERY_STAT(WeaponTrace), true, GetAvatarActorFromActorInfo());
	TraceParams.bReturnPhysicalMaterial = true;

	FHitResult Hit(ForceInit);
	GetWorld()->LineTraceSingleByChannel(Hit, StartTrace, EndTrace, COLLISION_WEAPON, TraceParams);

	return Hit;
}