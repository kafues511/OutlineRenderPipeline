// Copyright 2024 kafues511. All Rights Reserved.

#include "OutlineControlConsoleActor.h"
#include "OutlineSubsystem.h"

AOutlineControlConsoleActor::AOutlineControlConsoleActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AOutlineControlConsoleActor::BeginPlay()
{
	Super::BeginPlay();
	
	if (UOutlineSubsystem* Subsystem = UOutlineSubsystem::GetCurrent(GetWorld()))
	{
		Subsystem->OverrideOutlineSettings(OutlineSettings);
	}
}

void AOutlineControlConsoleActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

#if WITH_EDITOR
void AOutlineControlConsoleActor::RerunConstructionScripts()
{
	Super::RerunConstructionScripts();
}

void AOutlineControlConsoleActor::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	if (UOutlineSubsystem* Subsystem = UOutlineSubsystem::GetCurrent(GetWorld()))
	{
		Subsystem->OverrideOutlineSettings(OutlineSettings);
	}
}
#endif
