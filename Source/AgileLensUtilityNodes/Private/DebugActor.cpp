// Fill out your copyright notice in the Description page of Project Settings.


#include "DebugActor.h"

// Sets default values
ADebugActor::ADebugActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADebugActor::BeginPlay()
{
	Super::BeginPlay();

	static FAutoConsoleCommand HelloWorld(
	TEXT("CLAMS"),
	TEXT("Description of what the command does"),
	FConsoleCommandDelegate::CreateLambda([]()
	{
		UE_LOG(LogTemp, Warning, TEXT("SO MANY CLAMS"));
		GLog->Log(TEXT("CLAMLORDS"));
	})
	);
}

// Called every frame
void ADebugActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

