// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GasAbilities : ModuleRules
{
	public GasAbilities(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", "CoreUObject", "Engine", "InputCore", 
			"EnhancedInput", "GameplayAbilities",  "GameplayTags", "GameplayTasks"
        });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Include public and private paths
		PublicIncludePaths.Add("GasAbilities");
		//PublicIncludePaths.Add("GasAbilities/Public");
		//PrivateIncludePaths.Add("GasAbilities/Private");
	}
}
