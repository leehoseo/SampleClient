// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SampleUnrealClient/SampleUnrealClientGameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSampleUnrealClientGameModeBase() {}
// Cross Module References
	SAMPLEUNREALCLIENT_API UClass* Z_Construct_UClass_ASampleUnrealClientGameModeBase_NoRegister();
	SAMPLEUNREALCLIENT_API UClass* Z_Construct_UClass_ASampleUnrealClientGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_SampleUnrealClient();
// End Cross Module References
	void ASampleUnrealClientGameModeBase::StaticRegisterNativesASampleUnrealClientGameModeBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASampleUnrealClientGameModeBase);
	UClass* Z_Construct_UClass_ASampleUnrealClientGameModeBase_NoRegister()
	{
		return ASampleUnrealClientGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_ASampleUnrealClientGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASampleUnrealClientGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_SampleUnrealClient,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASampleUnrealClientGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "SampleUnrealClientGameModeBase.h" },
		{ "ModuleRelativePath", "SampleUnrealClientGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASampleUnrealClientGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASampleUnrealClientGameModeBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASampleUnrealClientGameModeBase_Statics::ClassParams = {
		&ASampleUnrealClientGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_ASampleUnrealClientGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASampleUnrealClientGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASampleUnrealClientGameModeBase()
	{
		if (!Z_Registration_Info_UClass_ASampleUnrealClientGameModeBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASampleUnrealClientGameModeBase.OuterSingleton, Z_Construct_UClass_ASampleUnrealClientGameModeBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASampleUnrealClientGameModeBase.OuterSingleton;
	}
	template<> SAMPLEUNREALCLIENT_API UClass* StaticClass<ASampleUnrealClientGameModeBase>()
	{
		return ASampleUnrealClientGameModeBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASampleUnrealClientGameModeBase);
	struct Z_CompiledInDeferFile_FID_SampleUnrealClient_Source_SampleUnrealClient_SampleUnrealClientGameModeBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SampleUnrealClient_Source_SampleUnrealClient_SampleUnrealClientGameModeBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASampleUnrealClientGameModeBase, ASampleUnrealClientGameModeBase::StaticClass, TEXT("ASampleUnrealClientGameModeBase"), &Z_Registration_Info_UClass_ASampleUnrealClientGameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASampleUnrealClientGameModeBase), 716014895U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SampleUnrealClient_Source_SampleUnrealClient_SampleUnrealClientGameModeBase_h_3477765386(TEXT("/Script/SampleUnrealClient"),
		Z_CompiledInDeferFile_FID_SampleUnrealClient_Source_SampleUnrealClient_SampleUnrealClientGameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SampleUnrealClient_Source_SampleUnrealClient_SampleUnrealClientGameModeBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
