// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/SAttributeComponent.h"

// Sets default values for this component's properties
USAttributeComponent::USAttributeComponent()
{
	/*����ֵ*/
	Health = 100;
	HealthMax = 100;
	/*����ֵ*/
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

// �Ƿ����
bool USAttributeComponent::IsAlive() const
{
	return Health > 0.0f;
}

// �Ƿ���Ѫ
bool USAttributeComponent::IsFullHealth() const
{
	return Health == HealthMax;
}

// ����ֵ��ȡ
float USAttributeComponent::GetHealth()
{
	return Health;
}

// �������ֵ��ȡ
float USAttributeComponent::GetHealthMax()
{
	return HealthMax;
}

// ����ֵ�ı�
bool USAttributeComponent::ApplyHealthChange(AActor* InstigatordActor, float Delta)
{
	float OldHealth = Health;
	float NewHealth = FMath::Clamp(Health + Delta, 0.0f, HealthMax); // ����NewHealth��������Χ
	float ActualDelta = NewHealth - OldHealth; // ������ι�����������ֵ������ֵ����ȡʵ�ʵ��˺���ֵ

	Health = NewHealth;
	
	if (ActualDelta != 0) // ��⵽�˺�
	{
		OnHealthChanged.Broadcast(InstigatordActor, this, NewHealth, Delta);
	}

	UE_LOG(LogTemp, Log, TEXT("Health Has Change, NewHealth = %f, Delta = %f."), NewHealth, ActualDelta);

	return ActualDelta > 0;
}

// �����Ƿ�Ϊ��
bool USAttributeComponent::IsEmptyEnergy() const
{
	return Energy > 0.0f;
}

// �����Ƿ�����
bool USAttributeComponent::IsFullEnergy() const
{
	return Energy == EnergyMax;
}

// ����ֵ��ȡ
float USAttributeComponent::GetEnergy()
{
	return Energy;
}

// �����ֵ��ȡ
float USAttributeComponent::GetEnergyMax()
{
	return EnergyMax;
}

// ����ֵ�ı�
bool USAttributeComponent::ApplyEnergyChange(float Delta)
{
	Energy += Delta;

	return true;
}
