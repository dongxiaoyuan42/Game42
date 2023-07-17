// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SEnergyWidget.generated.h"

class USAttributeComponent; // �������
class UMaterialInstanceDynamic; // ��̬���ʽӿ�

UCLASS()
class GAME42_API USEnergyWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	// ���캯��
	USEnergyWidget(const FObjectInitializer& ObjectInitializer);

protected:

	UPROPERTY(BlueprintReadOnly, Category = "Player Energy")
	FText TEnergy; // ����ֵ

	UPROPERTY(BlueprintReadOnly, Category = "Player Energy")
	float Energy; // ����ֵ

	UPROPERTY(BlueprintReadOnly, Category = "Player Energy")
	float MaxEnergy; // �����ֵ

	UPROPERTY(BlueprintReadOnly, Category = "Player Energy")
	float EnergyRate; // ����ֵ�ٷֱ�

	UPROPERTY(BlueprintReadWrite, Category = "Player Energy")
	UMaterialInstanceDynamic* EnergyMaterial; // ����������

protected:
	
	virtual void NativeConstruct() override; // UI�������ʱ������¼�

	UFUNCTION(BlueprintCallable)
	void GetEnergyChange(AActor* InstigatordActor, USAttributeComponent* OwningComp, float Energy, float Delta); // �����ı�ʱ����UI
	
	bool EnergyChangeCommon(float Energy); // ��ͨ���¾���ֵ����
};
