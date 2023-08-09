// Fill out your copyright notice in the Description page of Project Settings.


#include "QualitySettings.h"

void UQualitySettings::SetQualitySettings(APlayerController* PC, int f1, int f2, int f3, int f4, int f5, int f6, int f7,
	int f8, int f9, int f10, int f11)
{
	FString f1s = FString::Printf(TEXT("sg.AntiAliasingQuality %i"), FMath::Clamp(f1, 0, 3));
	FString f2s = FString::Printf(TEXT("sg.EffectsQuality %i"), FMath::Clamp(f2, 0, 3));
	FString f3s = FString::Printf(TEXT("sg.PostProcessQuality %i"), FMath::Clamp(f3, 0, 3));
	FString f4s = FString::Printf(TEXT("sg.ShadowQuality %i"), FMath::Clamp(f4, 0, 3));
	FString f5s = FString::Printf(TEXT("sg.TextureQuality %i"), FMath::Clamp(f5, 0, 3));
	FString f6s = FString::Printf(TEXT("sg.ReflectionQuality %i"), FMath::Clamp(f6, 0, 3));
	FString f7s = FString::Printf(TEXT("sg.GlobalIlluminationQuality %i"), FMath::Clamp(f7, 0, 3));
	FString f8s = FString::Printf(TEXT("sg.ViewDistanceQuality %i"), FMath::Clamp(f8, 0, 3));
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
