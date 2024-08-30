// Copyright 2024 kafues511. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SceneViewExtension.h"

class UOutlineSubsystem;

/**
 * ポストプロセスなアウトライン描画機能
 */
class OUTLINERENDERPIPELINE_API FOutlineViewExtension : public FSceneViewExtensionBase
{
public:
	FOutlineViewExtension(const FAutoRegister& AutoRegister, UOutlineSubsystem* InOutlineSubsystem);

	virtual ~FOutlineViewExtension() = default;
	virtual void SetupViewFamily(FSceneViewFamily& InViewFamily) override {}
	virtual void SetupView(FSceneViewFamily& InViewFamily, FSceneView& InView) override {}
	virtual void BeginRenderViewFamily(FSceneViewFamily& InViewFamily) override {}

	/**
	 * Called right before Post Processing rendering begins
	 */
	virtual void PrePostProcessPass_RenderThread(FRDGBuilder& GraphBuilder, const FSceneView& View, const FPostProcessingInputs& Inputs) override;

public:
	/**  */
	void Invalidate();

private:
	/**  */
	UOutlineSubsystem* OutlineSubsystem;
};
