// Fill out your copyright notice in the Description page of Project Settings.


#include "NetworkTools.h"

FString UNetworkTools::GetLocalIP(bool ReturnPort)
{
	bool canBindAll;
	TSharedRef<FInternetAddr> localAddr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->GetLocalHostAddr(*GLog, canBindAll);

	// Convert the FInternetAddr to a string
	if (ReturnPort)
		return localAddr->ToString(true);  
	else
		return localAddr->ToString(false); // false indicates we don't want to include the port number
}
