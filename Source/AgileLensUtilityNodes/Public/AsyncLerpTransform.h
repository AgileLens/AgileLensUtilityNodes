// AsyncLerpTransform.h
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "AsyncLerpTransform.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTransformLerpFinished, FTransform, FinalValue);

UCLASS(BlueprintType)
class AGILELENSUTILITYNODES_API UAsyncLerpTransform : public UObject
{
	GENERATED_BODY()

public:

	UAsyncLerpTransform();

	UFUNCTION(BlueprintCallable, Category = "Agile Lens", meta = (WorldContext = "WorldContextObject"))
	static UAsyncLerpTransform* LerpTransform(UObject* WorldContextObject, FTransform StartValue, FTransform EndValue, float Duration);

	UPROPERTY(BlueprintAssignable)
	FOnTransformLerpFinished OnLerpFinished;

private:

	UFUNCTION()
	void HandleLerpTick();

	FTransform StartValue;
	FTransform EndValue;
	float Duration;
	float ElapsedTime;
	FTimerHandle LerpTimerHandle;
	TWeakObjectPtr<UWorld> TargetWorld;
};
