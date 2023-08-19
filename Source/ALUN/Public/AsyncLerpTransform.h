#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncLerpTransform.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTransformLerpProgress, FTransform, CurrentValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTransformLerpFinished, FTransform, FinalValue);

UCLASS()
class ALUN_API UAsyncLerpTransform : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Agile Lens|Async", meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	static UAsyncLerpTransform* LerpTransform(UObject* WorldContextObject, FTransform StartValue, FTransform EndValue, float Duration, FTransform& CurrentTransform);

	UPROPERTY(BlueprintAssignable)
	FOnTransformLerpProgress OnProgress;

	UPROPERTY(BlueprintAssignable)
	FOnTransformLerpFinished OnCompleted;

private:
	void HandleLerpTick();

	FTransform StartValue;
	FTransform EndValue;
	float Duration;
	float ElapsedTime;
	FTimerHandle LerpTimerHandle;
	TWeakObjectPtr<UWorld> TargetWorld;
};
