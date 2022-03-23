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

		// 아래 에러 수정용
		// 심각도	코드	설명	프로젝트	파일	줄	비표시 오류(Suppression) 상태
		// 오류 C4668   '_WIN32_WINNT_WIN10_RS5'은(는) 전처리기 매크로로 정의되어 있지 않으므로
        // '#if/#elif'에 해당하는 '0'으로 바뀝니다.	SampleClient C:\Program Files(x86)\Windows Kits\10\include\10.0.19041.0\um\winioctl.h   14093
		PublicDefinitions.Add("WIN32_LEAN_AND_MEAN");
	}
}
