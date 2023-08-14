// AsyncLerpTransform.cpp
#include "AsyncLerpTransform.h"

UAsyncLerpTransform::UAsyncLerpTransform()
{
	ElapsedTime = 0.0f;
}

UAsyncLerpTransform* UAsyncLerpTransform::LerpTransform(UObject* WorldContextObject, FTransform StartValue, FTransform EndValue, float Duration)
{
	UAsyncLerpTransform* LerpTask = NewObject<UAsyncLerpTransform>();
	LerpTask->StartValue = StartValue;
	LerpTask->EndValue = EndValue;
	LerpTask->Duration = Duration;
	LerpTask->TargetWorld = WorldContextObject->GetWorld();

	LerpTask->TargetWorld->GetTimerManager().SetTimer(LerpTask->LerpTimerHandle, LerpTask, &UAsyncLerpTransform::HandleLerpTick, 0.01667f, true);

	return LerpTask;
}

void UAsyncLerpTransform::HandleLerpTick()
{
	ElapsedTime += 0.01667f;

	// Calculate lerp value for the transform
	FVector LerpedLocation = FMath::Lerp(StartValue.GetLocation(), EndValue.GetLocation(), ElapsedTime / Duration);
	FQuat LerpedRotation = FQuat::Slerp(StartValue.GetRotation(), EndValue.GetRotation(), ElapsedTime / Duration);
	FVector LerpedScale = FMath::Lerp(StartValue.GetScale3D(), EndValue.GetScale3D(), ElapsedTime / Duration);
	
	FTransform CurrentTransform(LerpedRotation, LerpedLocation, LerpedScale);

	// Check if we've finished
	if (ElapsedTime >= Duration)
	{
		TargetWorld->GetTimerManager().ClearTimer(LerpTimerHandle);
		OnLerpFinished.Broadcast(EndValue);
		return;
	}

	OnLerpFinished.Broadcast(CurrentTransform);
}
