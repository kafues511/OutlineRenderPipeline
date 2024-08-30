// Copyright 2024 kafues511. All Rights Reserved.

#include "OutlineSubsystem.h"
#include "OutlineViewExtension.h"

void UOutlineSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	// Initializing Scene view extension responsible for rendering regions.
	ViewExtension = FSceneViewExtensions::NewExtension<FOutlineViewExtension>(this);
}

void UOutlineSubsystem::Deinitialize()
{
	ENQUEUE_RENDER_COMMAND(OutlineSubsystem_Deinitialize)([this](FRHICommandListImmediate& RHICmdList)
	{
		ViewExtension->Invalidate();
		ViewExtension.Reset();
		ViewExtension = nullptr;
	});
}

UOutlineSubsystem* UOutlineSubsystem::GetCurrent(const UWorld* World)
{
	return UWorld::GetSubsystem<UOutlineSubsystem>(World);
}

const FOutlineSettings& UOutlineSubsystem::GetOutlineSettings() const
{
	return OutlineSettings;
}

void UOutlineSubsystem::SetOutlineSettings(FOutlineSettings NewValue)
{
	OutlineSettings = NewValue;
}

#define SET_PP(NAME) \
if (NewValue.bOverride_##NAME) \
{ \
	Value.NAME = NewValue.NAME; \
} \

void UOutlineSubsystem::OverrideOutlineSettings(const FOutlineSettings& NewValue)
{
	FOutlineSettings& Value = OutlineSettings;

	SET_PP(Enabled);
	SET_PP(Radius);
	SET_PP(Bias);
	SET_PP(Intensity);
	SET_PP(Color);
}

const FOutlineSettings UOutlineSubsystem::GetOutlineSettingsForLock() const
{
	FScopeLock Lock(&CriticalSection);
	return OutlineSettings;
}
