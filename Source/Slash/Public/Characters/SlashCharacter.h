// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "CharacterTypes.h"
#include "SlashCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UGroomComponent;
class UInputMappingContext;
class UInputAction;
class AItem;
class AWeapon;
class UAnimMontage;

UCLASS()
class SLASH_API ASlashCharacter : public ACharacter
{
	GENERATED_BODY()

// Member Functions:
public:
	ASlashCharacter();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

	/*
	* Input callbacks
	*/
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Interact(const FInputActionValue& Value);
	void Attack(const FInputActionValue& Value);

	UFUNCTION(BlueprintCallable)
	void FinishEquipping();

	/*
	* Montages
	*/
	void PlayAttackMontage();
	void PlayEquipMontage(FName SectionName);

	UFUNCTION(BlueprintCallable)
	void AttackEnd();

	UFUNCTION(BlueprintCallable)
	void Disarm();

	UFUNCTION(BlueprintCallable)
	void Arm();

	UFUNCTION(BlueprintCallable)
	bool CanAttack();

	UFUNCTION(BlueprintCallable)
	bool CanDisarm();

	UFUNCTION(BlueprintCallable)
	bool CanArm();

// Member variables:
protected:
	/*
	* Input mapping and actions
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input)
	UInputMappingContext* SlashContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input)
	UInputAction* MoveAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input)
	UInputAction* LookAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input)
	UInputAction* JumpAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input)
	UInputAction* InteractAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input)
	UInputAction* AttackAction;

	/*
	* Animation montages
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Montages)
	UAnimMontage* AttackMontage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Montages)
	UAnimMontage* EquipMontage;

	/*
	* States
	*/
	UPROPERTY(BlueprintReadOnly)
	ECharacterState CharacterState = ECharacterState::Unarmed;

	UPROPERTY(BlueprintReadWrite)
	EActionState ActionState = EActionState::Unoccupied;

private:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* ViewCamera;

	UPROPERTY(VisibleAnywhere, Category = Hair)
	UGroomComponent* Hair;

	UPROPERTY(VisibleAnywhere, Category = Hair)
	UGroomComponent* Eyebrows;

	UPROPERTY(VisibleInstanceOnly)
	AItem* OverlappingItem;

	UPROPERTY(VisibleAnywhere, Category = Weapon)
	AWeapon* EquippedWeapon;

// Getters and setters:
public:
	FORCEINLINE void SetOverlappingItem(AItem* Item) { OverlappingItem = Item; }
	FORCEINLINE ECharacterState GetCharacterState() const { return CharacterState; }

};
