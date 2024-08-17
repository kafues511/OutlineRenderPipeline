// Copyright kafues511, Inc. All Rights Reserved.

#include "OutlineSubsystem.h"
#include "OutlineViewExtension.h"

void UOutlineSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	UWorld* World = GetWorld();
	check(World != nullptr);

	// Initializing Scene view extension responsible for rendering regions.
	ViewExtension = FSceneViewExtensions::NewExtension<FOutlineViewExtension>();
}

void UOutlineSubsystem::Deinitialize()
{
	ViewExtension.Reset();
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
