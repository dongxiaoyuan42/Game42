// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SAttributeComponent.generated.h"

// 属性改变事件
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnAttributeChanged, AActor*, InstigatordActor, USAttributeComponent*, OwningComp, float, NewValue, float, Delta);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class GAME42_API USAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USAttributeComponent();


};
