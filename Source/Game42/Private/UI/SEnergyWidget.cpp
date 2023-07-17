// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SEnergyWidget.h"
#include "Component/SAttributeComponent.h"
#include "Materials/MaterialInstanceDynamic.h"

// 构造函数
USEnergyWidget::USEnergyWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	
}

// UI构造完成时绑定相关事件
void USEnergyWidget::NativeConstruct()
{
	// 获取玩家
	APawn* PlayerPawn = GetOwningPlayerPawn();
	if (PlayerPawn)
	{
		// 获取玩家属性组件
		USAttributeComponent* AttributeComp = Cast<USAttributeComponent>(PlayerPawn->GetComponentByClass(USAttributeComponent::StaticClass()));
		if (ensureAlways(AttributeComp))
		{

		}
	}
}

// 精力改变时更新UI
void USEnergyWidget::GetEnergyChange(AActor* InstigatordActor, USAttributeComponent* OwningComp, float Energy, float Delta)
{

}

// 普通更新精力值函数
bool USEnergyWidget::EnergyChangeCommon(float Energy)
{

}
