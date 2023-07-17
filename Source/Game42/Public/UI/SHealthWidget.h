// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SHealthWidget.generated.h"


class USAttributeComponent; // �������
class UMaterialInstanceDynamic; // ��̬���ʽӿ�

/**
 * 
 */
UCLASS()
class GAME42_API USHealthWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	// ���캯��
	USHealthWidget(const FObjectInitializer& ObjectInitializer);

protected:

	UPROPERTY(BlueprintReadOnly, Category = "Player Health")
	FText THealth; // ����ֵ

	UPROPERTY(BlueprintReadOnly, Category = "Player Health")
	float Health; // ����ֵ

	UPROPERTY(BlueprintReadOnly, Category = "Player Health")
	float MaxHealth; // �������ֵ

	UPROPERTY(BlueprintReadOnly, Category = "Player Health")
	float HealthRate; // ����ֵ�ٷֱ�

	UPROPERTY(BlueprintReadWrite, Category = "Player Health")
	UMaterialInstanceDynamic* HealthMaterial; // Ѫ������


protected:

	// UI�������ʱ������¼�
	virtual void NativeConstruct() override;

	// ����ֵ�ı�ʱ����UI
	UFUNCTION(BlueprintCallable)
	void GetHealthChange(AActor* InstigatordActor, USAttributeComponent* OwningComp, float NewHealth, float Delta);

	// ��ͨ��������ֵ����
	bool HealthChangeCommon(float NewHealth);
};
