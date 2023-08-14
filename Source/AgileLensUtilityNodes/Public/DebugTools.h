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
		bool bPrintToScreen = true,
		bool bPrintToLog = true,
		FLinearColor TextColor = FLinearColor::Red,
		float Duration = 2,
		FString DebugGroup = FString(TEXT("")),
		bool bStartEnabled = false
		);
};
