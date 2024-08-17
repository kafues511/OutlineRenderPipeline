// Copyright 2024 kafues511. All Rights Reserved.

#include "OutlineRenderPipelineModule.h"
#include "ShaderCore.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "FOutlineRenderPipelineModule"

void FOutlineRenderPipelineModule::StartupModule()
{
	FString PluginShaderDir = FPaths::Combine(IPluginManager::Get().FindPlugin(TEXT("OutlineRenderPipeline"))->GetBaseDir(), TEXT("Shaders"));
	AddShaderSourceDirectoryMapping(TEXT("/Plugin/OutlineRenderPipeline"), PluginShaderDir);
}

void FOutlineRenderPipelineModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FOutlineRenderPipelineModule, OutlineRenderPipelineModule)
