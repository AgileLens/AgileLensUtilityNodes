// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SocketSubsystem.h"
#include "IPAddress.h"
#include "NetworkTools.generated.h"

/**
 * 
 */
UCLASS()
class ALUN_API UNetworkTools : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, meta = (Category = "Agile Lens|Networking"))
	static FString GetLocalIP(bool ReturnPort);
};
