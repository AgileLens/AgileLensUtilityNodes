// Fill out your copyright notice in the Description page of Project Settings.


#include "QualitySettings.h"

void UQualitySettings::SetQualitySettings(APlayerController* PC, int f1, int f2, int f3, int f4, int f5, int f6, int f7,
	int f8, int f9, int f10, int f11)
{
	FString f1s = FString::Printf(TEXT("sg.AntiAliasingQuality %i"), FMath::Clamp(f1, 0, 4));
	FString f2s = FString::Printf(TEXT("sg.EffectsQuality %i"), FMath::Clamp(f2, 0, 4));
	FString f3s = FString::Printf(TEXT("sg.PostProcessQuality %i"), FMath::Clamp(f3, 0, 4));
	FString f4s = FString::Printf(TEXT("sg.ShadowQuality %i"), FMath::Clamp(f4, 0, 4));
	FString f5s = FString::Printf(TEXT("sg.TextureQuality %i"), FMath::Clamp(f5, 0, 4));
	FString f6s = FString::Printf(TEXT("sg.ReflectionQuality %i"), FMath::Clamp(f6, 0, 4));
	FString f7s = FString::Printf(TEXT("sg.GlobalIlluminationQuality %i"), FMath::Clamp(f7, 0, 4));
	FString f8s = FString::Printf(TEXT("sg.ViewDistanceQuality %i"), FMath::Clamp(f8, 0, 4));
	FString f9s = FString::Printf(TEXT("r.MaterialQualityLevel %i"), FMath::Clamp(f9, 0, 3));
	FString f10s = FString::Printf(TEXT("vr.PixelDensity %f"), FMath::Clamp(f10 / 100.0f, 0.1f, 2.0f));
	FString f11s = FString::Printf(TEXT("r.screenpercentage %i"), FMath::Clamp(f11, 10, 200));
	
	PC->ConsoleCommand(f1s);
	PC->ConsoleCommand(f2s);
	PC->ConsoleCommand(f3s);
	PC->ConsoleCommand(f4s);
	PC->ConsoleCommand(f5s);
	PC->ConsoleCommand(f6s);
	PC->ConsoleCommand(f7s);
	PC->ConsoleCommand(f8s);
	PC->ConsoleCommand(f9s);
	PC->ConsoleCommand(f10s);
	PC->ConsoleCommand(f11s);
}

void UQualitySettings::GetQualitySettings(int& f1, int& f2, int& f3, int& f4, int& f5, int& f6,
	int& f7, int& f8, int& f9, int& f10, int& f11)
{
	IConsoleVariable* CVar1 = IConsoleManager::Get().FindConsoleVariable(TEXT("sg.AntiAliasingQuality"));
	IConsoleVariable* CVar2 = IConsoleManager::Get().FindConsoleVariable(TEXT("sg.EffectsQuality"));
	IConsoleVariable* CVar3 = IConsoleManager::Get().FindConsoleVariable(TEXT("sg.PostProcessQuality"));
	IConsoleVariable* CVar4 = IConsoleManager::Get().FindConsoleVariable(TEXT("sg.ShadowQuality"));
	IConsoleVariable* CVar5 = IConsoleManager::Get().FindConsoleVariable(TEXT("sg.TextureQuality"));
	IConsoleVariable* CVar6 = IConsoleManager::Get().FindConsoleVariable(TEXT("sg.ReflectionQuality"));
	IConsoleVariable* CVar7 = IConsoleManager::Get().FindConsoleVariable(TEXT("sg.GlobalIlluminationQuality"));
	IConsoleVariable* CVar8 = IConsoleManager::Get().FindConsoleVariable(TEXT("sg.ViewDistanceQuality"));
	IConsoleVariable* CVar9 = IConsoleManager::Get().FindConsoleVariable(TEXT("r.MaterialQualityLevel"));
	IConsoleVariable* CVar10 = IConsoleManager::Get().FindConsoleVariable(TEXT("vr.PixelDensity"));
	IConsoleVariable* CVar11 = IConsoleManager::Get().FindConsoleVariable(TEXT("r.screenpercentage"));
	f1 = CVar1->GetInt();
	f2 = CVar2->GetInt();
	f3 = CVar3->GetInt();
	f4 = CVar4->GetInt();
	f5 = CVar5->GetInt();
	f6 = CVar6->GetInt();
	f7 = CVar7->GetInt();
	f8 = CVar8->GetInt();
	f9 = CVar9->GetInt();
	f10 = CVar10->GetInt();
	f11= CVar11->GetInt();
}

FString UQualitySettings::GetActiveXRRuntime()
{
	if (GEngine && GEngine->XRSystem.IsValid())
	{
		return GEngine->XRSystem->GetSystemName().ToString();
	}
	return FString(TEXT("No Active XR Runtime"));
	/*
	if (IXRTrackingSystem* XRSystem = GEngine->XRSystem.Get())
	{
		return XRSystem->GetSystemName().ToString();
	}

	return "None";
	*/
}


