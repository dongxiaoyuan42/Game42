//Fill out your copyright notice in the Description page of Project Settings.


#include "Game/SGameplayFunctionLibrary.h"
#include "Component/SAttributeComponent.h"


// 造成伤害函数
// 调用TargetActor（目标）的属性组件的生命改变函数造成伤害
bool USGameplayFunctionLibrary::ApplyDamage(AActor* DamageCauser, AActor* TargetActor, float DamageAmount)
{
	if (!IsValid(TargetActor))
	{
		return false;
	}

	// 获得目标的属性组件
	USAttributeComponent* AttributeComp = Cast<USAttributeComponent>(TargetActor->GetComponentByClass(USAttributeComponent::StaticClass()));
	if (AttributeComp)
	{
		return AttributeComp->ApplyHealthChange(DamageCauser, -DamageAmount);
	}
	return false;
}