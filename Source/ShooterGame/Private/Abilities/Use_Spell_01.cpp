// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/Use_Spell_01.h"
#include "public/player/ShooterCharacter.h"
#include "Weapons/ShooterWeapon.h"
#include "AbilitySystemComponent.h"

UUse_Spell_01::UUse_Spell_01()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	FGameplayTag Ability1Tag = FGameplayTag::RequestGameplayTag(FName("Ability.Skill.Ability1"));
	AbilityTags.AddTag(Ability1Tag);
	ActivationOwnedTags.AddTag(Ability1Tag);
	AbilityInputID = AbilityInput::UseAbility1;

	CancelAbilitiesWithTag.AddTag(FGameplayTag::RequestGameplayTag(FName("Ability.Movement.Sprint")));
}

void UUse_Spell_01::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	//CommitAbility(Handle,ActorInfo,ActivationInfo);

	
	
}

void UUse_Spell_01::InputReleased(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo)
{
	BPI_InputReleased();
	if (ActorInfo != NULL && ActorInfo->AvatarActor != NULL)
	{
		
		//CancelAbility(Handle, ActorInfo, ActivationInfo, true);
	}
}

void UUse_Spell_01::CancelAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateCancelAbility)
{
	Super::CancelAbility(Handle, ActorInfo, ActivationInfo, bReplicateCancelAbility);
	/*if (ScopeLockCount > 0)
	{
		WaitingToExecute.Add(FPostLockDelegate::CreateUObject(this, &UUse_Spell_01::CancelAbility, Handle, ActorInfo, ActivationInfo, bReplicateCancelAbility));
		return;
	}*/

	/*AShooterCharacter* TempPlayer = CastChecked<AShooterCharacter>(CurrentActorInfo->AvatarActor);
	if(TempPlayer)
	{
		StopWeaponFire(TempPlayer);
	}*/
	
}

void UUse_Spell_01::CommitExecute(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo)
{
	Super::CommitExecute(Handle, ActorInfo, ActivationInfo);
	/*if(ActorInfo->AvatarActor->GetLocalRole() == ROLE_Authority)
	{
		AShooterCharacter* TempPlayer = CastChecked<AShooterCharacter>(ActorInfo->AvatarActor);
		if(!TempPlayer)
		{
			EndAbility(CurrentSpecHandle,CurrentActorInfo,CurrentActivationInfo,true,true);
		}
		else
		{
			OnStartFire(TempPlayer);
		}
	}*/
}

void UUse_Spell_01::OnStartFire(AShooterCharacter* Shooter)
{
	AShooterPlayerController* MyPC = Cast<AShooterPlayerController>(Shooter->GetController());
	if (MyPC && MyPC->IsGameInputAllowed())
	{
		// if (Shooter->IsRunning())
		// {
		// 	Shooter->SetRunning(false, false);
		// }
		StartWeaponFire(Shooter);
	}
}

void UUse_Spell_01::StartWeaponFire(AShooterCharacter* Shooter)
{
	if (!Shooter->GetbWantsToFire())
	{
		Shooter->SetbWantsToFire(true);
		if (Shooter->GetCurrentWeapon())
		{
			Shooter->GetCurrentWeapon()->StartFire();
		}
	}
}

void UUse_Spell_01::StopWeaponFire(AShooterCharacter* Shooter)
{
	if (Shooter->GetbWantsToFire())
	{
		Shooter->SetbWantsToFire(false);
		if (Shooter->GetCurrentWeapon())
		{
			Shooter->GetCurrentWeapon()->StopFire();
		}
	}
}