// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SEnergyWidget.h"
#include "Component/SAttributeComponent.h"
#include "Materials/MaterialInstanceDynamic.h"

// ���캯��
USEnergyWidget::USEnergyWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	
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

		}
	}
}

// �����ı�ʱ����UI
void USEnergyWidget::GetEnergyChange(AActor* InstigatordActor, USAttributeComponent* OwningComp, float Energy, float Delta)
{

}

// ��ͨ���¾���ֵ����
bool USEnergyWidget::EnergyChangeCommon(float Energy)
{

}
