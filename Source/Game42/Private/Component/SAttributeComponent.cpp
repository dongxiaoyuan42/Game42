// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/SAttributeComponent.h"

// Sets default values for this component's properties
USAttributeComponent::USAttributeComponent()
{
	/*生命值*/
	Health = 100;
	HealthMax = 100;
	/*精力值*/
	Energy = 100;
	EnergyMax = 100;
}

USAttributeComponent* USAttributeComponent::GetAttributes(AActor* FromActor)
{
	if (FromActor)
	{
		return Cast<USAttributeComponent>(FromActor->GetComponentByClass(USAttributeComponent::StaticClass()));
	}

	return nullptr;
}

// 是否活着
bool USAttributeComponent::IsAlive() const
{
	return Health > 0.0f;
}

// 是否满血
bool USAttributeComponent::IsFullHealth() const
{
	return Health == HealthMax;
}

// 生命值获取
float USAttributeComponent::GetHealth()
{
	return Health;
}

// 最大生命值获取
float USAttributeComponent::GetHealthMax()
{
	return HealthMax;
}

// 生命值改变
bool USAttributeComponent::ApplyHealthChange(AActor* InstigatordActor, float Delta)
{
	float OldHealth = Health;
	float NewHealth = FMath::Clamp(Health + Delta, 0.0f, HealthMax); // 限制NewHealth不超过范围
	float ActualDelta = NewHealth - OldHealth; // 限制这次攻击不把生命值降到负值，获取实际的伤害数值

	Health = NewHealth;
	
	if (ActualDelta != 0) // 检测到伤害
	{
		OnHealthChanged.Broadcast(InstigatordActor, this, NewHealth, Delta);
	}

	UE_LOG(LogTemp, Log, TEXT("Health Has Change, NewHealth = %f, Delta = %f."), NewHealth, ActualDelta);

	return ActualDelta > 0;
}

// 精力是否为空
bool USAttributeComponent::IsEmptyEnergy() const
{
	return Energy > 0.0f;
}

// 精力是否已满
bool USAttributeComponent::IsFullEnergy() const
{
	return Energy == EnergyMax;
}

// 精力值获取
float USAttributeComponent::GetEnergy()
{
	return Energy;
}

// 最大精力值获取
float USAttributeComponent::GetEnergyMax()
{
	return EnergyMax;
}

// 精力值改变
bool USAttributeComponent::ApplyEnergyChange(float Delta)
{
	Energy += Delta;

	return true;
}
