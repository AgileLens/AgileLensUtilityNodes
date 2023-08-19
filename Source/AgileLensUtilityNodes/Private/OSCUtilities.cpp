// Fill out your copyright notice in the Description page of Project Settings.


#include "OSCUtilities.h"

#include "JsonObjectConverter.h"

//#include "OSC/Private/OSCMessagePacket.h"

void UOSCUtilities::ReturnTransform(FString InputString, FTransform& Transform)
{
	FString lx, ly, lz, rp, ry, rr, sx, sy, sz;
	const FRegexPattern RegPattern(TEXT("=\\s*([^ ]+)"));

	FRegexMatcher RegMatcher(RegPattern, InputString);

	RegMatcher.FindNext() ? lx = RegMatcher.GetCaptureGroup(1) : "";;
	RegMatcher.FindNext() ? ly = RegMatcher.GetCaptureGroup(1) : "";;
	RegMatcher.FindNext() ? lz = RegMatcher.GetCaptureGroup(1) : "";;
	RegMatcher.FindNext() ? rp = RegMatcher.GetCaptureGroup(1) : "";;
	RegMatcher.FindNext() ? ry = RegMatcher.GetCaptureGroup(1) : "";;
	RegMatcher.FindNext() ? rr = RegMatcher.GetCaptureGroup(1) : "";;
	RegMatcher.FindNext() ? sx = RegMatcher.GetCaptureGroup(1) : "";;
	RegMatcher.FindNext() ? sy = RegMatcher.GetCaptureGroup(1) : "";;
	RegMatcher.FindNext() ? sz = RegMatcher.GetCaptureGroup(1) : "";;

	Transform = {
		FRotator{FCString::Atof(*rp), FCString::Atof(*ry), FCString::Atof(*rr)},
		FVector{FCString::Atof(*lx), FCString::Atof(*ly), FCString::Atof(*lz)},
		FVector{FCString::Atof(*sx), FCString::Atof(*sy), FCString::Atof(*sz)}
	};
}

void UOSCUtilities::ReturnClientAndTransform(FString InputString, FString& ClientString,
                                             FTransform& Transform)
{
	FString lx, ly, lz, rp, ry, rr, sx, sy, sz;
	const FRegexPattern ClientRegPattern(TEXT("Client:\\s*(.*?)\\s*Translation"));
	const FRegexPattern RegPattern(TEXT("=\\s*([^ ]+)"));

	FRegexMatcher ClientRegMatcher(ClientRegPattern, ClientString);
	FRegexMatcher RegMatcher(RegPattern, ClientString);

	RegMatcher.FindNext() ? InputString = RegMatcher.GetCaptureGroup(0) : "";;

	RegMatcher.FindNext() ? lx = RegMatcher.GetCaptureGroup(1) : "";;
	RegMatcher.FindNext() ? ly = RegMatcher.GetCaptureGroup(1) : "";;
	RegMatcher.FindNext() ? lz = RegMatcher.GetCaptureGroup(1) : "";;
	RegMatcher.FindNext() ? rp = RegMatcher.GetCaptureGroup(1) : "";;
	RegMatcher.FindNext() ? ry = RegMatcher.GetCaptureGroup(1) : "";;
	RegMatcher.FindNext() ? rr = RegMatcher.GetCaptureGroup(1) : "";;
	RegMatcher.FindNext() ? sx = RegMatcher.GetCaptureGroup(1) : "";;
	RegMatcher.FindNext() ? sy = RegMatcher.GetCaptureGroup(1) : "";;
	RegMatcher.FindNext() ? sz = RegMatcher.GetCaptureGroup(1) : "";;

	Transform = {
		FRotator{FCString::Atof(*rp), FCString::Atof(*ry), FCString::Atof(*rr)},
		FVector{FCString::Atof(*lx), FCString::Atof(*ly), FCString::Atof(*lz)},
		FVector{FCString::Atof(*sx), FCString::Atof(*sy), FCString::Atof(*sz)}
	};
}


void UOSCUtilities::SendOscString(FOSCMessage& OutMessage, UOSCClient* PinOscClient, FString SendIP, int32 Port,
                                  FString ClientName, FString Address,
                                  FString MessageString, bool ShouldDestroy)
{
	//UE_LOG(LogTemp, Warning, TEXT("1"));
	if (!IsValid(PinOscClient))
	{
		//UE_LOG(LogTemp, Warning, TEXT("2"));
		
		
		UOSCClient* OSCClient = NewObject<UOSCClient>(GetTransientPackage());
		
		const FOSCAddress OSCAddress = Address;
		OutMessage.SetAddress(Address);

	
		OSCClient->Connect();
		OSCClient->SetSendIPAddress(SendIP, Port);

		UOSCManager::AddString(OutMessage, MessageString);


		
		OSCClient->SendOSCMessage(OutMessage);
		UOSCManager::ClearMessage(OutMessage);

		//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("Is not valid"));
		//UE_LOG(LogTemp, Warning, TEXT("Is not valid"));
		if (ShouldDestroy)
			OSCClient->MarkPendingKill();
	}
	else
	{
		UOSCClient* OSCClient = PinOscClient;
		const FOSCAddress OSCAddress = Address;
		OutMessage.SetAddress(Address);

		UOSCManager::AddString(OutMessage, MessageString);

		OSCClient->SendOSCMessage(OutMessage);
		UOSCManager::ClearMessage(OutMessage);
		OSCClient->MarkPendingKill();
		//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("Is valid"));
		//UE_LOG(LogTemp, Warning, TEXT("Is valid"));
		if (ShouldDestroy)
			OSCClient->MarkPendingKill();
	}
}

void UOSCUtilities::SendOscStruct(FOSCMessage& OutMessage, UOSCClient* PinOscClient, FString SendIP, int32 Port,
                                  FString ClientName,
                                  FString Address, FClientStruct ClientStruct, bool ShouldDestroy)
{
	FString JSONPayload;
	FJsonObjectConverter::UStructToJsonObjectString(ClientStruct, JSONPayload, 0, 0);
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, (TEXT("%s"), JSONPayload));
	UE_LOG(LogTemp, Warning, TEXT("%s"), *JSONPayload);
	if (!PinOscClient->IsValidLowLevel())
	{
		UOSCClient* OSCClient = NewObject<UOSCClient>(GetTransientPackage());
		const FOSCAddress OSCAddress = Address;
		OutMessage.SetAddress(Address);

		OSCClient->Connect();
		OSCClient->SetSendIPAddress(SendIP, Port);

		UOSCManager::AddString(OutMessage, JSONPayload);
		OSCClient->SendOSCMessage(OutMessage);
		UOSCManager::ClearMessage(OutMessage);

		if (ShouldDestroy)
			OSCClient->MarkPendingKill();
	}
	else
	{
		UOSCClient* OSCClient = PinOscClient;
		const FOSCAddress OSCAddress = Address;
		OutMessage.SetAddress(Address);

		UOSCManager::AddString(OutMessage, JSONPayload);
		OSCClient->SendOSCMessage(OutMessage);
		UOSCManager::ClearMessage(OutMessage);

		if (ShouldDestroy)
			OSCClient->MarkPendingKill();
	}
}

void UOSCUtilities::SendOscTransform(FOSCMessage& OutMessage, UOSCClient* PinOscClient, FString SendIP, int32 Port,
	FString ClientName, FString Address, FTransform ClientTransform, bool ShouldDestroy)
{
	FString ClientTransformString = ClientTransform.ToString();
	UE_LOG(LogTemp, Warning, TEXT("%s"), *ClientTransformString);
	if (!PinOscClient->IsValidLowLevel())
	{
		UOSCClient* OSCClient = NewObject<UOSCClient>(GetTransientPackage());
		const FOSCAddress OSCAddress = Address;
		OutMessage.SetAddress(Address);

		OSCClient->Connect();
		OSCClient->SetSendIPAddress(SendIP, Port);

		UOSCManager::AddString(OutMessage, ClientTransformString);
		OSCClient->SendOSCMessage(OutMessage);
		UOSCManager::ClearMessage(OutMessage);

		if (ShouldDestroy)
			OSCClient->MarkPendingKill();
	}
	else
	{
		UOSCClient* OSCClient = PinOscClient;
		const FOSCAddress OSCAddress = Address;
		OutMessage.SetAddress(Address);

		UOSCManager::AddString(OutMessage, ClientTransformString);
		OSCClient->SendOSCMessage(OutMessage);
		UOSCManager::ClearMessage(OutMessage);

		if (ShouldDestroy)
			OSCClient->MarkPendingKill();
	}
}

void UOSCUtilities::ReturnStruct(FString InputString, TArray<FClientStruct>& ClientStruct)
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("Return Struct"));
	FJsonObjectConverter::JsonArrayStringToUStruct<FClientStruct>(InputString, &ClientStruct, 0, 0);
	UE_LOG(LogTemp, Warning, TEXT("Return Struct"));
}

void UOSCUtilities::ReturnArray(FString InputString, TArray<FClientStruct>& StructArray)
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("Return Array"));
	FJsonObjectConverter::JsonArrayStringToUStruct(InputString, &StructArray, 0, 0);
	UE_LOG(LogTemp, Warning, TEXT("Return Array"));
}
