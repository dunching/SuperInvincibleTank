// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Project : ModuleRules
{
	public Project(ReadOnlyTargetRules Target) : base(Target)
	{
		// Include What You Use (IWYU)
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		DefaultBuildSettings = BuildSettingsVersion.Latest;

		CppCompileWarningSettings.UndefinedIdentifierWarningLevel = WarningLevel.Error;
		bWarningsAsErrors = true;
		bEnableExceptions = true;

		CppStandard = CppStandardVersion.Cpp20;

		bUseRTTI = true;

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
		}

		PublicDefinitions.Add("TESTPLAYERCHARACTERHOLDDATA = 0");
		PublicDefinitions.Add("TESTAICHARACTERHOLDDATA = 1");
		PublicDefinitions.Add("TESTRESOURCEBOXHOLDDATA = 1");
		PublicDefinitions.Add("TESTRAFFLE = 1");

		PublicIncludePaths.Add("Project");
		
		PrivateIncludePaths.Add("Project/Private");

		if (Target.bBuildEditor == true)
		{
			PrivateDependencyModuleNames.Add("UnrealEd");
		}

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			// 引擎内容
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"SlateCore",
			"Slate",
			"UMG",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"NavigationSystem",
			"ChaosVehicles",
			"ActorSequence",
			"NetCore",
			"ShaderConductor",
			"Json",
			"MediaAssets",
			"DatasmithContent",

			// 引擎插件
			"GameplayTags",
			"GameplayTasks",
			"GameplayAbilities",
			"GameplayStateTreeModule",
			"GameplayAbilities",
			"GameplayCameras",
			"Niagara",
			"PixelStreaming",

			// 插件
			"Common_UMG",
			"StateProcessor",
			"Utils",
			"Weather",
			
			// 其他模块
			"AssetRef",
			"CommonType",
			"GameOptions",
			"GameplayTagsLibrary",
			"Tools",
		});

		PublicDependencyModuleNames.AddRange(new string[]
		{
		});

		PrivateIncludePathModuleNames.AddRange(new string[]
		{
		});

		PublicIncludePathModuleNames.AddRange(new string[]
		{
		});
	}
}
