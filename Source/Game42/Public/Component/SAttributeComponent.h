// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SAttributeComponent.generated.h"

// ���Ըı��¼�
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnAttributeChanged, AActor*, InstigatordActor, USAttributeComponent*, OwningComp, float, NewValue, float, Delta);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class GAME42_API USAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USAttributeComponent();

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	static USAttributeComponent* GetAttributes(AActor* FromActor);

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes")
	float Health; // ����ֵ

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes")
	float HealthMax; // �������ֵ

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes")
	float Energy; // ����ֵ

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes")
	float EnergyMax; // �����ֵ

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes")
	float EnergyRecoverySpeed; // �����ظ��ٶ�

public:

	void BeginPlay();

	FTimerHandle MemberTimerHandle;

	/*����ֵ*/
	UFUNCTION(BlueprintCallable, Category = "Attributes")
	bool IsAlive() const; // �Ƿ����

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	bool IsFullHealth() const; // �Ƿ���Ѫ

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	float GetHealth(); // ����ֵ��ȡ

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	float GetHealthMax(); // �������ֵ��ȡ

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	bool ApplyHealthChange(AActor* InstigatordActor, float Delta); // ����ֵ�ı�

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChanged OnHealthChanged; // ����ֵ�ı��¼�

	/*����ֵ*/
	UFUNCTION(BlueprintCallable, Category = "Attributes")
	bool IsEmptyEnergy() const; // �����Ƿ�Ϊ��

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	bool IsFullEnergy() const; // �����Ƿ�����

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	float GetEnergy(); // ����ֵ��ȡ

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	float GetEnergyMax(); // �����ֵ��ȡ

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	bool ApplyEnergyChange(float Delta); // ����ֵ�ı�

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void EnergyRecovery(); // ����ֵ�Զ��ظ�

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChanged OnEnergyChanged; // ����ֵ�ı��¼�
};
