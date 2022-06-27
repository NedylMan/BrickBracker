// Fill out your copyright notice in the Description page of Project Settings.


#include "BallBounds.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Paddle_Player_Controller.h"
// Sets default values
ABallBounds::ABallBounds()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Box_Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	RootComponent = Box_Collision;
}

// Called when the game starts or when spawned
void ABallBounds::BeginPlay()
{
	Super::BeginPlay();
	Box_Collision->OnComponentBeginOverlap.AddDynamic(this, &ABallBounds::OnOverlapBegin);
	PlayerController_REF = Cast<APaddle_Player_Controller>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
}

// Called every frame
void ABallBounds::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABallBounds::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweep, 
	const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Ball"))
	{
		OtherActor->Destroy();
		PlayerController_REF->SpawnNewBall();
	}
}

