// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class GAME_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Destroyed() override;

	UFUNCTION(Category = "Projectile")
	void OnProjectileImpact(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	// �R���W�����e�X�g�Ɏg�p����鋅�̃R���|�[�l���g�B
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USphereComponent* SphereComponent;

	// �I�u�W�F�N�g�̎��o�I�ȕ\����񋟂��邽�߂Ɏg�p�����X�^�e�B�b�N���b�V���B
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UStaticMeshComponent* StaticMesh;

	// ���˕��̓������������邽�߂̈ړ��R���|�[�l���g�ł��B
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UProjectileMovementComponent* ProjectileMovementComponent;

	// ���˕������̃I�u�W�F�N�g�ɏՓ˂��A��������Ƃ��Ɏg�p�����p�[�e�B�N���B
	UPROPERTY(EditAnywhere, Category = "Effects")
	class UParticleSystem* ExplosionEffect;

	//���̔��˕����^����_���[�W�̎�ނƃ_���[�W�̑傫��
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage")
	TSubclassOf<class UDamageType> DamageType = UDamageType::StaticClass();

	//���̔��˕��ɂ���ė^������_���[�W�ł��B
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage")
	float Damage = 10.0f;
};
