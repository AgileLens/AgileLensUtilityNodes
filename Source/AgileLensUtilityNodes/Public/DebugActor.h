// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DebugSubsystem.h"
#include "HAL/IConsoleManager.h"
#include "DebugActor.generated.h"

UCLASS()
class AGILELENSUTILITYNODES_API ADebugActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADebugActor();

	//FAutoConsoleCommand MyConsoleCommand;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
