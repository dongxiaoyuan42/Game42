// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/SWeaponComponent.h"

// Sets default values for this component's properties
USWeaponComponent::USWeaponComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ǹе������
	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	WeaponMesh->SetSimulatePhysics(true);
	// Ĭ��7���ӵ�
	BulletNumMax = 7;


}

// ����
TSubclassOf<ASProjectileBase> USWeaponComponent::Fire()
{
	// ��֤���ӵ�
	if (BulletInGun.Num() <= 0)
	{
		return nullptr;
	}

	return BulletInGun.Pop();
}

// װ��
void USWeaponComponent::AddBullet(TSubclassOf<ASProjectileBase> ProjectileClass)
{
	// ���ܳ����ޣ�
	if (BulletInGun.Num() >= BulletNumMax)
	{
		return;
	}
	// ����������������������������������������������������������������������������������������������������������������������
	//if (ProjectileClass)
	//{
		BulletInGun.Add(ProjectileClass);
	//}
	// ����������������������������������������������������������������������������������������������������������������������
}

// װ��
void USWeaponComponent::AddAll()
{
	// ���ܳ����ޣ�
	int32 delta = BulletNumMax - BulletInGun.Num();
	if (delta <= 0)
	{
		return;
	}

	//if (ensure(DefaultBullet))
	//{
		// ����������������������������������������������������������������������������������������������������������������������
		BulletInGun.Append(&DefaultBullet, delta);
		// ����������������������������������������������������������������������������������������������������������������������
	//}
}


// Called when the game starts
void USWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void USWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}