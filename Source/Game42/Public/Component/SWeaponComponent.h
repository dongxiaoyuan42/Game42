// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SWeaponComponent.generated.h"

class UStaticMeshComponent; // 静态网格体
class ASProjectileBase; // 子弹基类

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAME42_API USWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USWeaponComponent();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	USWeaponComponent* GetWeaponComp(AActor* FromActor);

protected:

	UPROPERTY(VisibleAnywhere, Category = "Weapon")
	UStaticMeshComponent* WeaponMesh; // 枪械网格体

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	TSubclassOf<ASProjectileBase> DefaultBullet; // 默认子弹

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	int32 BulletNumMax; // 子弹上限

	UPROPERTY(BlueprintReadWrite, Category = "Weapon")
	TArray<TSubclassOf<ASProjectileBase>> BulletInGun; // 枪械中现存子弹

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	TSubclassOf<ASProjectileBase> Fire(); // 开火

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void AddBullet(TSubclassOf<ASProjectileBase> ProjectileClass); // 装弹

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void AddAll(); // 装满

	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
