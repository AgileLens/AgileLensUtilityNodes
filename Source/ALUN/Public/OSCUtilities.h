// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OSCClient.h"
#include "OSCManager.h"
#include "OSCMessage.h"
#include "OSCMessagePacket.h"
#include "OSCTypes.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonWriter.h"
#include "Serialization/JsonSerializer.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
//#include "CustomDebugSubsystem.h"
#include "OSCUtilities.generated.h"


USTRUCT(BlueprintType)
struct FClientStruct
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString ClientIP;

	UPROPERTY(BlueprintReadWrite)
	FTransform ClientTransform;
	
};


UCLASS()
class ALUN_API UOSCUtilities : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, meta = (Category = "Agile Lens|OSC"))
	static void SendOscString(FOSCMessage& OutMessage,
		UPARAM(DisplayName = "Existing Client (Opt)") UOSCClient* PinOscClient,
		FString SendIP,
		int32 Port,
		FString ClientName,
		FString Address,
		FString MessageString,
		UPARAM(DisplayName = "Destroy Client After?") bool ShouldDestroy
		);

	FOSCMessage* OutMessage;

	UFUNCTION(BlueprintCallable, meta = (Category = "Agile Lens|OSC"))
	static void SendOscStruct(FOSCMessage& OutMessage,
		UPARAM(DisplayName = "Existing Client (Opt)") UOSCClient* PinOscClient,
		FString SendIP,
		int32 Port,
		FString ClientName,
		FString Address,
		FClientStruct ClientStruct,
		UPARAM(DisplayName = "Destroy Client After?") bool ShouldDestroy = true
		);

	UFUNCTION(BlueprintCallable, meta = (Category = "Agile Lens|OSC"))
	static void SendOscTransform(FOSCMessage& OutMessage,
		UPARAM(DisplayName = "Existing Client (Opt)") UOSCClient* PinOscClient,
		FString SendIP,
		int32 Port,
		FString ClientName,
		FString Address,
		FTransform ClientTransform,
		UPARAM(DisplayName = "Destroy Client After?") bool ShouldDestroy = true
		);

	//------------------------------------------------------------------------------------------------------------------
	
	UFUNCTION(BlueprintCallable, meta = (Category="Agile Lens|OSC"))
	static void ReturnTransform(FString InputString, FTransform& Transform);

	UFUNCTION(BlueprintCallable, meta = (Category="Agile Lens|OSC"))
	static void ReturnClientAndTransform(FString InputString, FString& ClientString, FTransform& Transform);

	UFUNCTION(BlueprintCallable, meta = (Category = "Agile Lens|OSC"))
	static void ReturnStruct(FString InputString, TArray<FClientStruct>& ClientStruct);

	UFUNCTION(BlueprintCallable, meta = (Category = "Agile Lens|OSC"))
	static void ReturnArray(FString InputString, TArray<FClientStruct>& StructArray);
		
};

