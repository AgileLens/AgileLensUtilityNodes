// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "DebugSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class AGILELENSUTILITYNODES_API UDebugSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual bool ShouldCreateSubsystem(UObject* Outer) const { return true; }
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) {}
	
	virtual void Deinitialize() {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Category = "Agile Lens"))
	bool bDebuggingIsEnabled = false;

private:
	friend class FSubsystemCollectionBase;
	FSubsystemCollectionBase* InternalOwningSubsystem;
};
