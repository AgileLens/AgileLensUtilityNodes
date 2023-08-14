// Fill out your copyright notice in the Description page of Project Settings.


#include "DebugTools.h"

void UDebugTools::DebugPrintString(FString InputString, bool bPrintToScreen, bool bPrintToLog, FLinearColor TextColor,
	float Duration, FString DebugGroup, bool bStartEnabled)
{
	if (!InputString.IsEmpty())
	{
		UWorld* TheWorld = GEngine->GameViewport->GetWorld();
			
		if ( IsValid(TheWorld) )
		{
			if (UGameInstance* GameInstance = TheWorld->GetGameInstance())
			{
				if (UDebugSubsystem* DebugSubsystem = GameInstance->GetSubsystem<UDebugSubsystem>())
				{
					if (DebugSubsystem->bDebuggingIsEnabled)
					{
						if (bStartEnabled)
						{
							if (DebugSubsystem->StartedArray.Contains(DebugGroup))
							{
								if (DebugSubsystem->EnabledArray.Contains(DebugGroup))
								{
									if (bPrintToLog)
										UE_LOG(LogTemp, Warning, TEXT("%s"), *InputString);
								
									if(bPrintToScreen)
										GEngine->AddOnScreenDebugMessage(-1, Duration, TextColor.ToFColor(true), (TEXT("%s"), *InputString), true);
								}		
							}
							else
							{
								DebugSubsystem->EnabledArray.AddUnique(DebugGroup);
								DebugSubsystem->StartedArray.AddUnique(DebugGroup);
							
								if (bPrintToLog)
									UE_LOG(LogTemp, Warning, TEXT("%s"), *InputString);
								
								if(bPrintToScreen)
									GEngine->AddOnScreenDebugMessage(-1, Duration, TextColor.ToFColor(true), (TEXT("%s"), *InputString), true);
							}
						}
						else
						{
							if (DebugSubsystem->EnabledArray.Contains(DebugGroup))
							{
								if (bPrintToLog)
									UE_LOG(LogTemp, Warning, TEXT("%s"), *InputString);
								
								if(bPrintToScreen)
									GEngine->AddOnScreenDebugMessage(-1, Duration, TextColor.ToFColor(true), (TEXT("%s"), *InputString), true);
							}							
						}
					}
					
				}
			}
		}
	}
}
