// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BallBounds.generated.h"

class UBoxComponent;
class APaddle_Player_Controller;


UCLASS()
class BRICKBRACKER_API ABallBounds : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABallBounds();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UBoxComponent* Box_Collision;

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
			class UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweep, const FHitResult& SweepResult);


	APaddle_Player_Controller* PlayerController_REF;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
