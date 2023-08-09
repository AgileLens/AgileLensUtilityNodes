// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DebugSubsystem.h"
#include "DebugTools.generated.h"

/**
 * 
 */
UCLASS()
class AGILELENSUTILITYNODES_API UDebugTools : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, meta = (Category = "Agile Lens"))
	static void DebugPrintString(FString InputString,
		bool PrintToScreen = true,
		bool PrintToLog = true,
		FLinearColor TextColor = FLinearColor::Red,
		float Duration = 2
		);
};
