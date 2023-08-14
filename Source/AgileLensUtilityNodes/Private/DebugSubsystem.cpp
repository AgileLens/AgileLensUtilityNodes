// Fill out your copyright notice in the Description page of Project Settings.


#include "DebugSubsystem.h"

#include "DebugActor.h"

void UDebugSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Warning, TEXT("Debug subsystem setting up"));

	static FAutoConsoleCommandWithWorldAndArgs EnableCommand(
	TEXT("DebugEnableGroup"),
	TEXT("Enables this group in the debug subsystem"),
	FConsoleCommandWithWorldAndArgsDelegate::CreateLambda(
		[this](const TArray<FString>& Args, UWorld* World)
		{
			if (!Args.IsEmpty())
			{
				DebugEnableGroup(*Args[0]);
				UE_LOG(LogTemp, Warning, TEXT("Argument: %s"), *Args[0]);
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("No group names specified with command"));
			}
		})
	);
	
}

void UDebugSubsystem::DebugEnableGroup(FString GroupName)
{
	UE_LOG(LogTemp, Warning, TEXT("DANK CLAMS = %s"), *GroupName);
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, (TEXT("GCLAMS ALL DAY")));
	if (EnabledArray.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("HORSESHIT"));
		EnabledArray.Add(GroupName);
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, (TEXT("Added to empty")));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("BULLSHIT"));
		if (!GroupName.IsEmpty())
		{
			EnabledArray.Add(GroupName);
		}
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, (TEXT("Added to not empty")));
	}
}

void UDebugSubsystem::DebugDisableGroup(FString GroupName)
{
	EnabledArray.Remove(GroupName);
}