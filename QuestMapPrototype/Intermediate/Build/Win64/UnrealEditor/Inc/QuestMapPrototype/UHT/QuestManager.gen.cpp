// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "QuestMapPrototype/Quests/QuestManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeQuestManager() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
QUESTMAPPROTOTYPE_API UClass* Z_Construct_UClass_AQuestManager();
QUESTMAPPROTOTYPE_API UClass* Z_Construct_UClass_AQuestManager_NoRegister();
QUESTMAPPROTOTYPE_API UClass* Z_Construct_UClass_UQuestData_NoRegister();
UPackage* Z_Construct_UPackage__Script_QuestMapPrototype();
// End Cross Module References

// Begin Class AQuestManager
void AQuestManager::StaticRegisterNativesAQuestManager()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AQuestManager);
UClass* Z_Construct_UClass_AQuestManager_NoRegister()
{
	return AQuestManager::StaticClass();
}
struct Z_Construct_UClass_AQuestManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Quests/QuestManager.h" },
		{ "ModuleRelativePath", "Quests/QuestManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Quests_MetaData[] = {
		{ "Category", "Quest" },
		{ "ModuleRelativePath", "Quests/QuestManager.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Quests_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Quests;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AQuestManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AQuestManager_Statics::NewProp_Quests_Inner = { "Quests", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UQuestData_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AQuestManager_Statics::NewProp_Quests = { "Quests", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AQuestManager, Quests), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Quests_MetaData), NewProp_Quests_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AQuestManager_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AQuestManager_Statics::NewProp_Quests_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AQuestManager_Statics::NewProp_Quests,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AQuestManager_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AQuestManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_QuestMapPrototype,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AQuestManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AQuestManager_Statics::ClassParams = {
	&AQuestManager::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AQuestManager_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AQuestManager_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AQuestManager_Statics::Class_MetaDataParams), Z_Construct_UClass_AQuestManager_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AQuestManager()
{
	if (!Z_Registration_Info_UClass_AQuestManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AQuestManager.OuterSingleton, Z_Construct_UClass_AQuestManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AQuestManager.OuterSingleton;
}
template<> QUESTMAPPROTOTYPE_API UClass* StaticClass<AQuestManager>()
{
	return AQuestManager::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AQuestManager);
AQuestManager::~AQuestManager() {}
// End Class AQuestManager

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Quests_QuestManager_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AQuestManager, AQuestManager::StaticClass, TEXT("AQuestManager"), &Z_Registration_Info_UClass_AQuestManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AQuestManager), 733421670U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Quests_QuestManager_h_249878594(TEXT("/Script/QuestMapPrototype"),
	Z_CompiledInDeferFile_FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Quests_QuestManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Quests_QuestManager_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
