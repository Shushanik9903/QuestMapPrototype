// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "QuestMapPrototype/QuestMapPrototypeGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeQuestMapPrototypeGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
QUESTMAPPROTOTYPE_API UClass* Z_Construct_UClass_AQuestMapPrototypeGameMode();
QUESTMAPPROTOTYPE_API UClass* Z_Construct_UClass_AQuestMapPrototypeGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_QuestMapPrototype();
// End Cross Module References

// Begin Class AQuestMapPrototypeGameMode
void AQuestMapPrototypeGameMode::StaticRegisterNativesAQuestMapPrototypeGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AQuestMapPrototypeGameMode);
UClass* Z_Construct_UClass_AQuestMapPrototypeGameMode_NoRegister()
{
	return AQuestMapPrototypeGameMode::StaticClass();
}
struct Z_Construct_UClass_AQuestMapPrototypeGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "QuestMapPrototypeGameMode.h" },
		{ "ModuleRelativePath", "QuestMapPrototypeGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AQuestMapPrototypeGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AQuestMapPrototypeGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_QuestMapPrototype,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AQuestMapPrototypeGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AQuestMapPrototypeGameMode_Statics::ClassParams = {
	&AQuestMapPrototypeGameMode::StaticClass,
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
	0x008802ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AQuestMapPrototypeGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AQuestMapPrototypeGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AQuestMapPrototypeGameMode()
{
	if (!Z_Registration_Info_UClass_AQuestMapPrototypeGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AQuestMapPrototypeGameMode.OuterSingleton, Z_Construct_UClass_AQuestMapPrototypeGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AQuestMapPrototypeGameMode.OuterSingleton;
}
template<> QUESTMAPPROTOTYPE_API UClass* StaticClass<AQuestMapPrototypeGameMode>()
{
	return AQuestMapPrototypeGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AQuestMapPrototypeGameMode);
AQuestMapPrototypeGameMode::~AQuestMapPrototypeGameMode() {}
// End Class AQuestMapPrototypeGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_GBM_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_QuestMapPrototypeGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AQuestMapPrototypeGameMode, AQuestMapPrototypeGameMode::StaticClass, TEXT("AQuestMapPrototypeGameMode"), &Z_Registration_Info_UClass_AQuestMapPrototypeGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AQuestMapPrototypeGameMode), 2418308499U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_GBM_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_QuestMapPrototypeGameMode_h_2226842433(TEXT("/Script/QuestMapPrototype"),
	Z_CompiledInDeferFile_FID_Users_GBM_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_QuestMapPrototypeGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_GBM_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_QuestMapPrototypeGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
