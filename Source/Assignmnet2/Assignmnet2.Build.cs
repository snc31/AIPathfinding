// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Assignmnet2 : ModuleRules
{
	public Assignmnet2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
