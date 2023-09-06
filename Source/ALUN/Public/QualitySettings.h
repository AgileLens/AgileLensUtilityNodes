// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameFramework/PlayerController.h"
#include "XRPlatform.h"
#include "QualitySettings.generated.h"

/**
 * 
 */
UCLASS()
class ALUN_API UQualitySettings : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	public:
	
	/** 
	* Agile Lens visual quality setting node. Runs the console commands below. Hover over input pin for value ranges.
	* @param	f1	Value range: 0 - 3
	* @param	f2	Value range: 0 - 3
	* @param	f3	Value range: 0 - 3
	* @param	f4	Value range: 0 - 3
	* @param	f5	Value range: 0 - 3
	* @param	f6	Value range: 0 - 3
	* @param	f7	Value range: 0 - 3
	* @param	f8	Value range: 0 - 3
	* @param	f9	Value range: 0 - 3
	* @param	f10	Value range: 10 - 200 (Value divided by 100 for a float range of 0.1 - 2.0)
	* @param	f11	Value range: 10 - 200
	*/
	UFUNCTION(BlueprintCallable, meta = (Category = "Agile Lens|Settings"))
	static void SetQualitySettings(
		UPARAM(DisplayName = "Player Controller") APlayerController *PC,
		UPARAM(DisplayName = "Anti Aliasing Quality") int f1 = 0,
		UPARAM(DisplayName = "Effects Quality") int f2 = 0,
		UPARAM(DisplayName = "Post Process Quality") int f3 = 0,
		UPARAM(DisplayName = "Shadow Quality") int f4 = 1,
		UPARAM(DisplayName = "Texture Quality") int f5 = 0,
		UPARAM(DisplayName = "Reflection Quality") int f6 = 2,
		UPARAM(DisplayName = "Global Illumination Quality") int f7 = 1,
		UPARAM(DisplayName = "View Distance Quality") int f8 = 0,
		UPARAM(DisplayName = "Material Quality Level") int f9 = 0,
		UPARAM(DisplayName = "Pixel Density %") int f10 = 100,
		UPARAM(DisplayName = "Screen Percentage") int f11 = 100
		);

	UFUNCTION(BlueprintCallable, meta = (Category = "Agile Lens|Settings"))
	FString GetActiveXRRuntime();
};
