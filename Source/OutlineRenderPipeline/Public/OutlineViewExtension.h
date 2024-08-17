// Copyright kafues511, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SceneViewExtension.h"

/**
 * ポストプロセスなアウトライン描画機能
 */
class OUTLINERENDERPIPELINE_API FOutlineViewExtension : public FSceneViewExtensionBase
{
public:
	FOutlineViewExtension(const FAutoRegister& AutoRegister);

	virtual ~FOutlineViewExtension() = default;
	virtual void SetupViewFamily(FSceneViewFamily& InViewFamily) override {}
	virtual void SetupView(FSceneViewFamily& InViewFamily, FSceneView& InView) override {}
	virtual void BeginRenderViewFamily(FSceneViewFamily& InViewFamily) override {}

	/**
	 * Called right before Post Processing rendering begins
	 */
	virtual void PrePostProcessPass_RenderThread(FRDGBuilder& GraphBuilder, const FSceneView& View, const FPostProcessingInputs& Inputs) override;

};
