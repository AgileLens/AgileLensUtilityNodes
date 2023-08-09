// Fill out your copyright notice in the Description page of Project Settings.


#include "DebugTools.h"

void UDebugTools::DebugPrintString(FString InputString, bool PrintToScreen, bool PrintToLog, FLinearColor TextColor,
	float Duration)
{
	if (!InputString.IsEmpty())
	{
		UWorld* W = GEngine->GameViewport->GetWorld();
			
		if ( IsValid(W) )
		{
			UGameInstance* GameInstance = W->GetGameInstance();
			if (GameInstance)
			{
				if (GameInstance->GetSubsystem<UDebugSubsystem>()->bDebuggingIsEnabled)
				{
					if (PrintToLog)
						UE_LOG(LogTemp, Warning, TEXT("%s"), *InputString);
					
					if(PrintToScreen)
						GEngine->AddOnScreenDebugMessage(-1, Duration, TextColor.ToFColor(true), (TEXT("%s"), *InputString), true);
				}
				
			}
		}
	}
}
