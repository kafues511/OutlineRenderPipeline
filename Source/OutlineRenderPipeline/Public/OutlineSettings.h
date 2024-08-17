// Copyright 2024 kafues511. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OutlineSettings.generated.h"

/** 輪郭線の設定 */
USTRUCT(BlueprintType, meta = (HiddenByDefault))
struct FOutlineSettings
{
	GENERATED_USTRUCT_BODY()

	// first all bOverride_... as they get grouped together into bitfields

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Overrides, meta = (PinHiddenByDefault, InlineEditConditionToggle))
	uint8 bOverride_Enabled : 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Overrides, meta = (PinHiddenByDefault, InlineEditConditionToggle))
	uint8 bOverride_Radius : 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Overrides, meta = (PinHiddenByDefault, InlineEditConditionToggle))
	uint8 bOverride_Bias : 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Overrides, meta = (PinHiddenByDefault, InlineEditConditionToggle))
	uint8 bOverride_Intensity : 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Overrides, meta = (PinHiddenByDefault, InlineEditConditionToggle))
	uint8 bOverride_Color : 1;

	// -----------------------------------------------------------------------

	/** 輪郭線の有効性 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Outline Settings", meta = (editcondition = "bOverride_Enabled", DisplayName = "Enabled"))
	uint32 Enabled : 1;

	/** 線の太さ */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Outline Settings", meta = (editcondition = "bOverride_Radius", DisplayName = "Radius"))
	float Radius;

	/** 線の閾値 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Outline Settings", meta = (editcondition = "bOverride_Bias", DisplayName = "Bias"))
	float Bias;

	/** 線の濃さ */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Outline Settings", meta = (editcondition = "bOverride_Intensity", DisplayName = "Intensity"))
	float Intensity;

	/** 線の色 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Outline Settings", meta = (editcondition = "bOverride_Color", DisplayName = "Color"))
	FLinearColor Color;

	// -----------------------------------------------------------------------

	OUTLINERENDERPIPELINE_API FOutlineSettings();
};
