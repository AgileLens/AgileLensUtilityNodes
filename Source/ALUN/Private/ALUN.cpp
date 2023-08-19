// Copyright Epic Games, Inc. All Rights Reserved.

#include "ALUN.h"

#define LOCTEXT_NAMESPACE "FALUNModule"

void FALUNModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
}

void FALUNModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FALUNModule, ALUN)