// Fill out your copyright notice in the Description page of Project Settings.


#include "BuffActor/BuffActor.h"
#include "MyAbilitySystemComponent.h"
#include "MyWeaponAttributeSet.h"
#include "MyGameplayAbility.h"
#include <GameplayEffectTypes.h>

#include "ComponentUtils.h"

// Sets default values
ABuffActor::ABuffActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Our ability system component.
	AbilitySystemComponent = CreateDefaultSubobject<UMyAbilitySystemComponent>(TEXT("AbilitySystemComp"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	
	BuffDuration = 3.f; // 기본시간.
}

// Called when the game starts or when spawned
void ABuffActor::BeginPlay()
{
	Super::BeginPlay();
	
	//SetTargetActor(GetAttachParentActor()); // 이 액터는 반드시 액터에 붙어있어야합니다.
	
	if(HasAuthority())
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
		GiveAbilies();
	}


	//ActivateAllBuff();

	SetLifeSpan(BuffDuration);
}

void ABuffActor::ActivateAllBuff()
{
	if(TargetActor == nullptr) return;
	
	AttachToActor(TargetActor.Get(),FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	
	if(HasAuthority() && AbilitySystemComponent)
	{
		for( TSubclassOf<UMyGameplayAbility>& StartupAbility : Abilitys)
		{
			AbilitySystemComponent->TryActivateAbilityByClass(StartupAbility);
			//AbilitySystemComponent->TryActivateAbility(StartupAbility.GetDefaultObject()->GetCurrentAbilitySpecHandle());
		}
	}
}

void ABuffActor::DeactivateAllBuff()
{
	if(HasAuthority() && AbilitySystemComponent)
	{
		for( TSubclassOf<UMyGameplayAbility>& StartupAbility : Abilitys)
		{
			//AbilitySystemComponent->TryActivateAbility(StartupAbility.GetDefaultObject()->GetCurrentAbilitySpecHandle());
			AbilitySystemComponent->CancelAbility(StartupAbility.GetDefaultObject());
		}
	}
}

void ABuffActor::BeginDestroy()
{
	Super::BeginDestroy();
	DeactivateAllBuff();
}

UAbilitySystemComponent* ABuffActor::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ABuffActor::GiveAbilies()
{
	if(HasAuthority() && AbilitySystemComponent)
	{
		for( TSubclassOf<UMyGameplayAbility>& StartupAbility : Abilitys)
		{
			AbilitySystemComponent->GiveAbility(
				FGameplayAbilitySpec(StartupAbility, 1, static_cast<int32>(StartupAbility.GetDefaultObject()->AbilityInputID),this));
		}
	}
}

// Called every frame
void ABuffActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

