// Copyright kafues511, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class OutlineRenderPipeline : ModuleRules
{
	public OutlineRenderPipeline(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PrivateIncludePaths.AddRange(
			new string[] {
				Path.Combine(GetModuleDirectory("Renderer"), "Private"),
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"Projects",
				"RenderCore",
				"Renderer",
				"RHI",
			}
		);
	}
}
