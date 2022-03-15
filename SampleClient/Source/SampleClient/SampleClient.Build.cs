// Copyright Epic Games, Inc. All Rights Reserved.
using System.IO;
using UnrealBuildTool;

public class SampleClient : ModuleRules
{
	private string ModulePath
	{
		get { return ModuleDirectory; }
	}

	private string ThirdPartyPath
	{
		get { return Path.GetFullPath(Path.Combine(ModulePath, "../ThirdParty/")); }
	}

	private string BinariesPath
	{
		get { return Path.GetFullPath(Path.Combine(ModulePath, "../../Binaries/")); }
	}

	public SampleClient(ReadOnlyTargetRules Target) : base(Target)
	{
		PublicDefinitions.Add("WITH_MYTHIRDPARTYLIBRARY=1");

		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });

		bool isLibrarySupported = false;

		// CommonLib LibPath
		string commonLibPath = Path.Combine(ThirdPartyPath, "CommonLib");

		// Get Library & Binaries Path 
		string libPath = "", binaryPath = "";
		if (Target.Platform == UnrealTargetPlatform.Win64 )
		{
			libPath = Path.Combine(commonLibPath, "Libraries", Target.Platform.ToString());
			binaryPath = Path.Combine(BinariesPath, Target.Platform.ToString());

			isLibrarySupported = true;
		}
		else if (Target.Platform == UnrealTargetPlatform.Android)
		{
			isLibrarySupported = false;
		}
		else
		{
			string Err = string.Format("{0} dedicated server is made to depend on {1}. We want to avoid this, please correct module dependencies.", Target.Platform.ToString(), this.ToString()); System.Console.WriteLine(Err);
		}
		// 프로젝트 속성 - 포함 디렉터리에 아래 경로 추가
		PublicIncludePaths.Add("SampleClient/Resource");
		if (true == isLibrarySupported)
		{
			//Add Static Libraries
			PublicAdditionalLibraries.Add(Path.Combine(libPath, "CommonLib.lib"));

			//Add Include path 
			PublicIncludePaths.Add( Path.Combine(commonLibPath, "Include"));
		}

		//PublicDefinitions.Add("WITH_MYTHIRDPARTYLIBRARY=1");
		PublicDefinitions.Add(string.Format("WITH_COMMONLIB_BINDING={0}", isLibrarySupported ? 1 : 0));
	}
}
