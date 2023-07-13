// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SGameplayFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class GAME42_API USGameplayFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	// ‘Ï≥……À∫¶∫Ø ˝
	UFUNCTION(BlueprintCallable)
	static bool ApplyDamage(AActor* DamageCauser, AActor* TargetActor, float DamageAmount);

};
