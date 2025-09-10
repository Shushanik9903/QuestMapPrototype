// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "QuestMapPrototype/Quests/QuestDataAsset.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeQuestDataAsset() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
QUESTMAPPROTOTYPE_API UClass* Z_Construct_UClass_UQuestDataAsset();
QUESTMAPPROTOTYPE_API UClass* Z_Construct_UClass_UQuestDataAsset_NoRegister();
QUESTMAPPROTOTYPE_API UClass* Z_Construct_UClass_UQuestGoal_NoRegister();
QUESTMAPPROTOTYPE_API UScriptStruct* Z_Construct_UScriptStruct_FQuestEntry();
UPackage* Z_Construct_UPackage__Script_QuestMapPrototype();
// End Cross Module References

// Begin ScriptStruct FQuestEntry
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_QuestEntry;
class UScriptStruct* FQuestEntry::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_QuestEntry.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_QuestEntry.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FQuestEntry, (UObject*)Z_Construct_UPackage__Script_QuestMapPrototype(), TEXT("QuestEntry"));
	}
	return Z_Registration_Info_UScriptStruct_QuestEntry.OuterSingleton;
}
template<> QUESTMAPPROTOTYPE_API UScriptStruct* StaticStruct<FQuestEntry>()
{
	return FQuestEntry::StaticStruct();
}
struct Z_Construct_UScriptStruct_FQuestEntry_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Quests/QuestDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_QuestName_MetaData[] = {
		{ "Category", "Quest" },
		{ "ModuleRelativePath", "Quests/QuestDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
		{ "Category", "Quest" },
		{ "ModuleRelativePath", "Quests/QuestDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Goals_MetaData[] = {
		{ "Category", "Quest" },
		{ "ModuleRelativePath", "Quests/QuestDataAsset.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_QuestName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Description;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Goals_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Goals;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FQuestEntry>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FQuestEntry_Statics::NewProp_QuestName = { "QuestName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestEntry, QuestName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_QuestName_MetaData), NewProp_QuestName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FQuestEntry_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestEntry, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FQuestEntry_Statics::NewProp_Goals_Inner = { "Goals", nullptr, (EPropertyFlags)0x0104000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UQuestGoal_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FQuestEntry_Statics::NewProp_Goals = { "Goals", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestEntry, Goals), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Goals_MetaData), NewProp_Goals_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FQuestEntry_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestEntry_Statics::NewProp_QuestName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestEntry_Statics::NewProp_Description,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestEntry_Statics::NewProp_Goals_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestEntry_Statics::NewProp_Goals,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FQuestEntry_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FQuestEntry_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_QuestMapPrototype,
	nullptr,
	&NewStructOps,
	"QuestEntry",
	Z_Construct_UScriptStruct_FQuestEntry_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FQuestEntry_Statics::PropPointers),
	sizeof(FQuestEntry),
	alignof(FQuestEntry),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FQuestEntry_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FQuestEntry_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FQuestEntry()
{
	if (!Z_Registration_Info_UScriptStruct_QuestEntry.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_QuestEntry.InnerSingleton, Z_Construct_UScriptStruct_FQuestEntry_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_QuestEntry.InnerSingleton;
}
// End ScriptStruct FQuestEntry

// Begin Class UQuestDataAsset
void UQuestDataAsset::StaticRegisterNativesUQuestDataAsset()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UQuestDataAsset);
UClass* Z_Construct_UClass_UQuestDataAsset_NoRegister()
{
	return UQuestDataAsset::StaticClass();
}
struct Z_Construct_UClass_UQuestDataAsset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Quests/QuestDataAsset.h" },
		{ "ModuleRelativePath", "Quests/QuestDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Quests_MetaData[] = {
		{ "Category", "Quest" },
		{ "ModuleRelativePath", "Quests/QuestDataAsset.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Quests_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Quests;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UQuestDataAsset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UQuestDataAsset_Statics::NewProp_Quests_Inner = { "Quests", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FQuestEntry, METADATA_PARAMS(0, nullptr) }; // 77062175
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UQuestDataAsset_Statics::NewProp_Quests = { "Quests", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuestDataAsset, Quests), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Quests_MetaData), NewProp_Quests_MetaData) }; // 77062175
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UQuestDataAsset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestDataAsset_Statics::NewProp_Quests_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestDataAsset_Statics::NewProp_Quests,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestDataAsset_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UQuestDataAsset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_QuestMapPrototype,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestDataAsset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UQuestDataAsset_Statics::ClassParams = {
	&UQuestDataAsset::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UQuestDataAsset_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UQuestDataAsset_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestDataAsset_Statics::Class_MetaDataParams), Z_Construct_UClass_UQuestDataAsset_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UQuestDataAsset()
{
	if (!Z_Registration_Info_UClass_UQuestDataAsset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UQuestDataAsset.OuterSingleton, Z_Construct_UClass_UQuestDataAsset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UQuestDataAsset.OuterSingleton;
}
template<> QUESTMAPPROTOTYPE_API UClass* StaticClass<UQuestDataAsset>()
{
	return UQuestDataAsset::StaticClass();
}
UQuestDataAsset::UQuestDataAsset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UQuestDataAsset);
UQuestDataAsset::~UQuestDataAsset() {}
// End Class UQuestDataAsset

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Quests_QuestDataAsset_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FQuestEntry::StaticStruct, Z_Construct_UScriptStruct_FQuestEntry_Statics::NewStructOps, TEXT("QuestEntry"), &Z_Registration_Info_UScriptStruct_QuestEntry, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FQuestEntry), 77062175U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UQuestDataAsset, UQuestDataAsset::StaticClass, TEXT("UQuestDataAsset"), &Z_Registration_Info_UClass_UQuestDataAsset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UQuestDataAsset), 3983753252U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Quests_QuestDataAsset_h_3333567487(TEXT("/Script/QuestMapPrototype"),
	Z_CompiledInDeferFile_FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Quests_QuestDataAsset_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Quests_QuestDataAsset_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Quests_QuestDataAsset_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Quests_QuestDataAsset_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
