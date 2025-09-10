// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "QuestMapPrototype/Quests/QuestData.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeQuestData() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
QUESTMAPPROTOTYPE_API UClass* Z_Construct_UClass_UQuestData();
QUESTMAPPROTOTYPE_API UClass* Z_Construct_UClass_UQuestData_NoRegister();
QUESTMAPPROTOTYPE_API UClass* Z_Construct_UClass_UQuestGoal_NoRegister();
UPackage* Z_Construct_UPackage__Script_QuestMapPrototype();
// End Cross Module References

// Begin Class UQuestData
void UQuestData::StaticRegisterNativesUQuestData()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UQuestData);
UClass* Z_Construct_UClass_UQuestData_NoRegister()
{
	return UQuestData::StaticClass();
}
struct Z_Construct_UClass_UQuestData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Quests/QuestData.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Quests/QuestData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_QuestName_MetaData[] = {
		{ "Category", "Quest" },
		{ "ModuleRelativePath", "Quests/QuestData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
		{ "Category", "Quest" },
		{ "ModuleRelativePath", "Quests/QuestData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Goals_MetaData[] = {
		{ "Category", "Quest" },
		{ "ModuleRelativePath", "Quests/QuestData.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_QuestName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Description;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Goals_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Goals;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UQuestData>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UQuestData_Statics::NewProp_QuestName = { "QuestName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuestData, QuestName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_QuestName_MetaData), NewProp_QuestName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UQuestData_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuestData, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuestData_Statics::NewProp_Goals_Inner = { "Goals", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UQuestGoal_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UQuestData_Statics::NewProp_Goals = { "Goals", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuestData, Goals), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Goals_MetaData), NewProp_Goals_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UQuestData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestData_Statics::NewProp_QuestName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestData_Statics::NewProp_Description,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestData_Statics::NewProp_Goals_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestData_Statics::NewProp_Goals,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestData_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UQuestData_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_QuestMapPrototype,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestData_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UQuestData_Statics::ClassParams = {
	&UQuestData::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UQuestData_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UQuestData_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestData_Statics::Class_MetaDataParams), Z_Construct_UClass_UQuestData_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UQuestData()
{
	if (!Z_Registration_Info_UClass_UQuestData.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UQuestData.OuterSingleton, Z_Construct_UClass_UQuestData_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UQuestData.OuterSingleton;
}
template<> QUESTMAPPROTOTYPE_API UClass* StaticClass<UQuestData>()
{
	return UQuestData::StaticClass();
}
UQuestData::UQuestData(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UQuestData);
UQuestData::~UQuestData() {}
// End Class UQuestData

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Quests_QuestData_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UQuestData, UQuestData::StaticClass, TEXT("UQuestData"), &Z_Registration_Info_UClass_UQuestData, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UQuestData), 33407434U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Quests_QuestData_h_2586541369(TEXT("/Script/QuestMapPrototype"),
	Z_CompiledInDeferFile_FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Quests_QuestData_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Quests_QuestData_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
