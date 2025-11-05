// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GasAbilities : ModuleRules
{
	public GasAbilities(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", "CoreUObject", "Engine", // Essential Unreal Engine modules
			"InputCore", "EnhancedInput", // Input handling modules
			"GameplayAbilities", "GameplayTags", "GameplayTasks" // Gameplay Ability System modules
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
	}
}
