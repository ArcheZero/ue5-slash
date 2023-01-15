// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/HitInterface.h"
#include "Enemy.generated.h"

class UAnimMontage;
class USoundBase;

UCLASS()
class SLASH_API AEnemy : public ACharacter, public IHitInterface
{
	GENERATED_BODY()

// Member functions:
public:
	AEnemy();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void GetHit_Implementation(const FVector& ImpactPoint) override;

	void DirectionalHitReact(const FVector& ImpactPoint);

protected:
	virtual void BeginPlay() override;

	/**
	* Animation montages
	*/
	void PlayHitReactMontage(const FName& SectionName);

// Member variables:
protected:
	UPROPERTY(EditDefaultsOnly, Category = Montages)
	UAnimMontage* HitReactMontage;

	UPROPERTY(EditAnywhere, Category = Sounds)
	USoundBase* HitSound;

	UPROPERTY(EditAnywhere, Category = VFX)
	UParticleSystem* HitParticles;

};
