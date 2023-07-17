//Fill out your copyright notice in the Description page of Project Settings.


#include "Game/SGameplayFunctionLibrary.h"
#include "Component/SAttributeComponent.h"


// ����˺�����
// ����TargetActor��Ŀ�꣩����������������ı亯������˺�
bool USGameplayFunctionLibrary::ApplyDamage(AActor* DamageCauser, AActor* TargetActor, float DamageAmount)
{
	if (!IsValid(TargetActor))
	{
		return false;
	}

	// ���Ŀ����������
	USAttributeComponent* AttributeComp = Cast<USAttributeComponent>(TargetActor->GetComponentByClass(USAttributeComponent::StaticClass()));
	if (AttributeComp)
	{
		return AttributeComp->ApplyHealthChange(DamageCauser, -DamageAmount);
	}
	return false;
}