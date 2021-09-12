// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayEffect/GE_ExecutionCalculation.h"
#include "AbilitySystemComponent.h"

UGE_ExecutionCalculation::UGE_ExecutionCalculation(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	// AttStruct Attributes;
	//
	// RelevantAttributesToCapture.Add(Attributes.HealthDef); //RelevantAttributesToCapture is the array that contains all attributes you wish to capture, without exceptions. 
	// InvalidScopedModifierAttributes.Add(Attributes.HealthDef); //However, an attribute added here on top of being added in RelevantAttributesToCapture will still be captured, but will not be shown for potential in-function modifiers in the GameplayEffect blueprint, more on that later.

	// RelevantAttributesToCapture.Add(Attributes.BaseAttackPowerDef);
	// RelevantAttributesToCapture.Add(Attributes.DefenseMultiplierDef);
	// RelevantAttributesToCapture.Add(Attributes.AttackMultiplierDef);
}

void UGE_ExecutionCalculation::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams,
	FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
 //    AttStruct Attributes; //Creating the attribute struct, we will need its values later when we want to get the attribute values.
 //
 //    UAbilitySystemComponent* TargetAbilitySystemComponent = ExecutionParams.GetTargetAbilitySystemComponent(); //We put AbilitySystemComponents into little helper variables. Not necessary, but it helps keeping us from typing so much.
 //
 //    UAbilitySystemComponent* SourceAbilitySystemComponent = ExecutionParams.GetSourceAbilitySystemComponent();
 //
 //    AActor* SourceActor = SourceAbilitySystemComponent ? SourceAbilitySystemComponent->AvatarActor : nullptr; //If our AbilitySystemComponents are valid, we get each their owning actors and put them in variables. This is mostly to prevent crashing by trying to get the AvatarActor variable from
 //
 //    AActor* TargetActor = TargetAbilitySystemComponent ? TargetAbilitySystemComponent->AvatarActor : nullptr; //a null pointer.
 //
 //    const FGameplayEffectSpec & Spec = ExecutionParams.GetOwningSpec();
 //    const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
 //    const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags(); //Some more helper variables: Spec is the spec this execution originated from, and the Source/TargetTags are pointers to the tags granted to source/target actor, respectively.
 //
 //    FAggregatorEvaluateParameters EvaluationParameters; //We use these tags to set up an FAggregatorEvaluateParameters struct, which we will need to get the values of our captured attributes later in this function.
 //
 //    EvaluationParameters.SourceTags = SourceTags;
 //    EvaluationParameters.TargetTags = TargetTags;
 //
	// float Damage = 0.0f;
	//
 //    float Health = 0.f;
 //
 //    //Alright, this is where we get the attribute's captured value into our function. Damage().HealthDef is the definition of the attribute we want to get, we defined EvaluationParameters just above us, and Health is the variable where we will put the captured value into(the Health variable we just declared)
 //    ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(Attributes.HealthDef, EvaluationParameters, Health); 
 //
 //    float BaseAttackPower = 0.f;
 //    ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(Attributes.BaseAttackPowerDef, EvaluationParameters, BaseAttackPower); // We do this for all other attributes, as well.
 //
 //    float AttackMultiplier = 0.f;
 //    ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(Attributes.AttackMultiplierDef, EvaluationParameters, AttackMultiplier);
 //
 //    float DefensePower = 0.f;
 //    ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(Attributes.DefenseMultiplierDef, EvaluationParameters, DefensePower);
 //
 //    //Finally, we go through our simple example damage calculation. BaseAttackPower and AttackMultiplier come from soruce, DefensePower comes from target.
 //    float DamageDone = BaseAttackPower * AttackMultiplier * DefensePower;
 //
 //    //An optional step is to clamp to not take health lower than 0. This can be ignored, or implemented in the attribute sets' PostGameplayEffectExecution function. Your call, really.
 //    DamageDone = FMath::Min<float>( Damage, Health );
 //
 //    //Finally, we check if we even did any damage in this whole ordeal. If yes, then we will add an outgoing execution modifer to the Health attribute we got from our target, which is a modifier that can still be thrown out by the attribute system if it wishes to throw out the GameplayEffectExecutionCalculation.
 //    if (DamageDone > 0.f)
 //    {
 //        OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(Damage().HealthProperty, EGameplayModOp::Additive, -DamageDone));
 //    }
 //    //Congratulations, your damage calculation is complete!
}
