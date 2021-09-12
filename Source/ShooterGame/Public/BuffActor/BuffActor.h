// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilitySystemInterface.h"
#include <GameplayEffectTypes.h>
#include "BuffActor.generated.h"

UCLASS()
class SHOOTERGAME_API ABuffActor : public AActor, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuffActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ActivateAllBuff();

	void DeactivateAllBuff();
	
	virtual void BeginDestroy() override;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = Ability)
	TWeakObjectPtr<AActor> TargetActor;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = Ability)
	float BuffDuration;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = Ability)
	TArray<TSubclassOf<UMyGameplayAbility>> Abilitys;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities, meta = (AllowPrivateAccess = "true"))
	class UMyAbilitySystemComponent* AbilitySystemComponent;
	
	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
	void GiveAbilies();
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void SetTargetActor(AActor* Target){TargetActor = Target;};

	UFUNCTION(BlueprintCallable)
	AActor* GetTargetActor() const{ return TargetActor.Get();};
};
