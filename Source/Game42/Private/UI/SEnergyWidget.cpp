// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SEnergyWidget.h"
#include "Component/SAttributeComponent.h"
#include "Materials/MaterialInstanceDynamic.h"

// ���캯��
USEnergyWidget::USEnergyWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	MaxEnergy = 100.0f;
	EnergyChangeCommon(100.0f);
}

// UI�������ʱ������¼�
void USEnergyWidget::NativeConstruct()
{
	// ��ȡ���
	APawn* PlayerPawn = GetOwningPlayerPawn();
	if (PlayerPawn)
	{
		// ��ȡ����������
		USAttributeComponent* AttributeComp = Cast<USAttributeComponent>(PlayerPawn->GetComponentByClass(USAttributeComponent::StaticClass()));
		if (ensureAlways(AttributeComp))
		{
			// ���������������UI����
			MaxEnergy = AttributeComp->GetEnergyMax();
			EnergyChangeCommon(AttributeComp->GetEnergy());
			// ������������ OnHealthChanged �� GetHealthChange
			AttributeComp->OnEnergyChanged.AddDynamic(this, &USEnergyWidget::GetEnergyChange); //
		}
		// ��ʼʱUI��ʼ��
		EnergyChangeCommon(Energy); //
		EnergyMaterial->SetScalarParameterValue("PrograssAlpha", EnergyRate);
	}
}

// �����ı�ʱ����UI
void USEnergyWidget::GetEnergyChange(AActor* InstigatordActor, USAttributeComponent* OwningComp, float NewEnergy, float Delta)
{
	EnergyChangeCommon(NewEnergy);
	// Ѫ�����ʸ��£��Ѿ����ú��ˣ�ֻ��ҪPrograssAlpha��HealthRate��
	EnergyMaterial->SetScalarParameterValue("PrograssAlpha", EnergyRate);
}

// ��ͨ���¾���ֵ����
bool USEnergyWidget::EnergyChangeCommon(float NewEnergy)
{
	Energy = NewEnergy;
	TEnergy = FText::FromString(FString::Printf(TEXT("%.2f"), Energy));
	EnergyRate = Energy / MaxEnergy;

	return true;
}
