// Copyright 2024 kafues511. All Rights Reserved.

#include "OutlineSettings.h"

FOutlineSettings::FOutlineSettings()
{
	// to set all bOverride_.. by default to false
	FMemory::Memzero(this, sizeof(FOutlineSettings));

	Enabled = false;
	Radius = 1.0f;
	Bias = 2.0f;
	Intensity = 1.0f;
	Color = FLinearColor::Black;
}
