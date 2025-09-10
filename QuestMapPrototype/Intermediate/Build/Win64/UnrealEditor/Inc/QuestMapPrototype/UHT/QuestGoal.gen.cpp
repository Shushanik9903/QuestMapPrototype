// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "QuestMapPrototype/Quests/QuestGoal.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeQuestGoal() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
QUESTMAPPROTOTYPE_API UClass* Z_Construct_UClass_UQuestGoal();
QUESTMAPPROTOTYPE_API UClass* Z_Construct_UClass_UQuestGoal_NoRegister();
QUESTMAPPROTOTYPE_API UEnum* Z_Construct_UEnum_QuestMapPrototype_EGoalType();
UPackage* Z_Construct_UPackage__Script_QuestMapPrototype();
// End Cross Module References

// Begin Enum EGoalType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EGoalType;
static UEnum* EGoalType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EGoalType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EGoalType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_QuestMapPrototype_EGoalType, (UObject*)Z_Construct_UPackage__Script_QuestMapPrototype(), TEXT("EGoalType"));
	}
	return Z_Registration_Info_UEnum_EGoalType.OuterSingleton;
}
template<> QUESTMAPPROTOTYPE_API UEnum* StaticEnum<EGoalType>()
{
	return EGoalType_StaticEnum();
}
struct Z_Construct_UEnum_QuestMapPrototype_EGoalType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "Dynamic.Comment", "/**\n * \n */" },
		{ "Dynamic.Name", "EGoalType::Dynamic" },
		{ "ModuleRelativePath", "Quests/QuestGoal.h" },
		{ "Static.Comment", "/**\n * \n */" },
		{ "Static.Name", "EGoalType::Static" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EGoalType::Static", (int64)EGoalType::Static },
		{ "EGoalType::Dynamic", (int64)EGoalType::Dynamic },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_QuestMapPrototype_EGoalType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_QuestMapPrototype,
	nullptr,
	"EGoalType",
	"EGoalType",
	Z_Construct_UEnum_QuestMapPrototype_EGoalType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_QuestMapPrototype_EGoalType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_QuestMapPrototype_EGoalType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_QuestMapPrototype_EGoalType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_QuestMapPrototype_EGoalType()
{
	if (!Z_Registration_Info_UEnum_EGoalType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EGoalType.InnerSingleton, Z_Construct_UEnum_QuestMapPrototype_EGoalType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EGoalType.InnerSingleton;
}
// End Enum EGoalType

// Begin Class UQuestGoal
void UQuestGoal::StaticRegisterNativesUQuestGoal()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UQuestGoal);
UClass* Z_Construct_UClass_UQuestGoal_NoRegister()
{
	return UQuestGoal::StaticClass();
}
struct Z_Construct_UClass_UQuestGoal_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Quests/QuestGoal.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Quests/QuestGoal.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GoalName_MetaData[] = {
		{ "Category", "Quest Goal" },
		{ "ModuleRelativePath", "Quests/QuestGoal.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GoalType_MetaData[] = {
		{ "Category", "Quest Goal" },
		{ "ModuleRelativePath", "Quests/QuestGoal.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetActor_MetaData[] = {
		{ "Category", "Quest Goal" },
		{ "ModuleRelativePath", "Quests/QuestGoal.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_GoalName;
	static const UECodeGen_Private::FBytePropertyParams NewProp_GoalType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_GoalType;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetActor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UQuestGoal>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UQuestGoal_Statics::NewProp_GoalName = { "GoalName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuestGoal, GoalName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GoalName_MetaData), NewProp_GoalName_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UQuestGoal_Statics::NewProp_GoalType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UQuestGoal_Statics::NewProp_GoalType = { "GoalType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuestGoal, GoalType), Z_Construct_UEnum_QuestMapPrototype_EGoalType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GoalType_MetaData), NewProp_GoalType_MetaData) }; // 2328082825
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuestGoal_Statics::NewProp_TargetActor = { "TargetActor", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuestGoal, TargetActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetActor_MetaData), NewProp_TargetActor_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UQuestGoal_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestGoal_Statics::NewProp_GoalName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestGoal_Statics::NewProp_GoalType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestGoal_Statics::NewProp_GoalType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestGoal_Statics::NewProp_TargetActor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestGoal_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UQuestGoal_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_QuestMapPrototype,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestGoal_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UQuestGoal_Statics::ClassParams = {
	&UQuestGoal::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UQuestGoal_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UQuestGoal_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestGoal_Statics::Class_MetaDataParams), Z_Construct_UClass_UQuestGoal_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UQuestGoal()
{
	if (!Z_Registration_Info_UClass_UQuestGoal.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UQuestGoal.OuterSingleton, Z_Construct_UClass_UQuestGoal_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UQuestGoal.OuterSingleton;
}
template<> QUESTMAPPROTOTYPE_API UClass* StaticClass<UQuestGoal>()
{
	return UQuestGoal::StaticClass();
}
UQuestGoal::UQuestGoal(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UQuestGoal);
UQuestGoal::~UQuestGoal() {}
// End Class UQuestGoal

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Quests_QuestGoal_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EGoalType_StaticEnum, TEXT("EGoalType"), &Z_Registration_Info_UEnum_EGoalType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2328082825U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UQuestGoal, UQuestGoal::StaticClass, TEXT("UQuestGoal"), &Z_Registration_Info_UClass_UQuestGoal, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UQuestGoal), 2804959200U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Quests_QuestGoal_h_3143718008(TEXT("/Script/QuestMapPrototype"),
	Z_CompiledInDeferFile_FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Quests_QuestGoal_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Quests_QuestGoal_h_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Quests_QuestGoal_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Quests_QuestGoal_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
