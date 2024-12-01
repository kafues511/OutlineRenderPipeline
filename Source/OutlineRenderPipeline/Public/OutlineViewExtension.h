// Copyright 2024 kafues511. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SceneViewExtension.h"
#include "OutlineSettings.h"

class UOutlineSubsystem;

/**
 * ポストプロセスなアウトライン描画機能
 */
class OUTLINERENDERPIPELINE_API FOutlineViewExtension : public FSceneViewExtensionBase
{
public:
	FOutlineViewExtension(const FAutoRegister& AutoRegister, UOutlineSubsystem* InOutlineSubsystem);

	virtual ~FOutlineViewExtension() = default;
	virtual void SetupViewFamily(FSceneViewFamily& InViewFamily) override;
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

	/**
	 * The final settings for the current viewer position.
	 * Setup by the main thread, passed to the render thread and never touched again by the main thread.
	 */
	FOutlineSettings FinalOutlineSettings;
};
