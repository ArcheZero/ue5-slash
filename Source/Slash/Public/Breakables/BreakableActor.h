// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/HitInterface.h"
#include "BreakableActor.generated.h"

class UGeometryCollectionComponent;

UCLASS()
class SLASH_API ABreakableActor : public AActor, public IHitInterface
{
	GENERATED_BODY()
	
// Member functions:
public:
	ABreakableActor();

	virtual void Tick(float DeltaTime) override;
	virtual void GetHit_Implementation(const FVector& ImpactPoint) override;

protected:
	virtual void BeginPlay() override;

// Member variables:
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UGeometryCollectionComponent* GeometryCollection;

};
