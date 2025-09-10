// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "QuestMapPrototype/Game/Controller/QuestMapPlayerController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeQuestMapPlayerController() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
QUESTMAPPROTOTYPE_API UClass* Z_Construct_UClass_AQuestMapPlayerController();
QUESTMAPPROTOTYPE_API UClass* Z_Construct_UClass_AQuestMapPlayerController_NoRegister();
QUESTMAPPROTOTYPE_API UEnum* Z_Construct_UEnum_QuestMapPrototype_EQuestName();
QUESTMAPPROTOTYPE_API UScriptStruct* Z_Construct_UScriptStruct_FQuestProgress();
UPackage* Z_Construct_UPackage__Script_QuestMapPrototype();
// End Cross Module References

// Begin Enum EQuestName
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EQuestName;
static UEnum* EQuestName_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EQuestName.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EQuestName.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_QuestMapPrototype_EQuestName, (UObject*)Z_Construct_UPackage__Script_QuestMapPrototype(), TEXT("EQuestName"));
	}
	return Z_Registration_Info_UEnum_EQuestName.OuterSingleton;
}
template<> QUESTMAPPROTOTYPE_API UEnum* StaticEnum<EQuestName>()
{
	return EQuestName_StaticEnum();
}
struct Z_Construct_UEnum_QuestMapPrototype_EQuestName_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Banana.Comment", "/**\n * \n */" },
		{ "Banana.Name", "EQuestName::Banana" },
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "ModuleRelativePath", "Game/Controller/QuestMapPlayerController.h" },
		{ "Orange.Comment", "/**\n * \n */" },
		{ "Orange.Name", "EQuestName::Orange" },
		{ "Strawberry.Comment", "/**\n * \n */" },
		{ "Strawberry.Name", "EQuestName::Strawberry" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EQuestName::Banana", (int64)EQuestName::Banana },
		{ "EQuestName::Strawberry", (int64)EQuestName::Strawberry },
		{ "EQuestName::Orange", (int64)EQuestName::Orange },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_QuestMapPrototype_EQuestName_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_QuestMapPrototype,
	nullptr,
	"EQuestName",
	"EQuestName",
	Z_Construct_UEnum_QuestMapPrototype_EQuestName_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_QuestMapPrototype_EQuestName_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_QuestMapPrototype_EQuestName_Statics::Enum_MetaDataParams), Z_Construct_UEnum_QuestMapPrototype_EQuestName_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_QuestMapPrototype_EQuestName()
{
	if (!Z_Registration_Info_UEnum_EQuestName.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EQuestName.InnerSingleton, Z_Construct_UEnum_QuestMapPrototype_EQuestName_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EQuestName.InnerSingleton;
}
// End Enum EQuestName

// Begin ScriptStruct FQuestProgress
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_QuestProgress;
class UScriptStruct* FQuestProgress::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_QuestProgress.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_QuestProgress.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FQuestProgress, (UObject*)Z_Construct_UPackage__Script_QuestMapPrototype(), TEXT("QuestProgress"));
	}
	return Z_Registration_Info_UScriptStruct_QuestProgress.OuterSingleton;
}
template<> QUESTMAPPROTOTYPE_API UScriptStruct* StaticStruct<FQuestProgress>()
{
	return FQuestProgress::StaticStruct();
}
struct Z_Construct_UScriptStruct_FQuestProgress_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Game/Controller/QuestMapPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_QuestName_MetaData[] = {
		{ "Category", "Quest" },
		{ "ModuleRelativePath", "Game/Controller/QuestMapPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_QuestCount_MetaData[] = {
		{ "Category", "Quest" },
		{ "ModuleRelativePath", "Game/Controller/QuestMapPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_QuestName_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_QuestName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_QuestCount;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FQuestProgress>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FQuestProgress_Statics::NewProp_QuestName_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FQuestProgress_Statics::NewProp_QuestName = { "QuestName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestProgress, QuestName), Z_Construct_UEnum_QuestMapPrototype_EQuestName, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_QuestName_MetaData), NewProp_QuestName_MetaData) }; // 1607759001
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FQuestProgress_Statics::NewProp_QuestCount = { "QuestCount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestProgress, QuestCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_QuestCount_MetaData), NewProp_QuestCount_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FQuestProgress_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestProgress_Statics::NewProp_QuestName_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestProgress_Statics::NewProp_QuestName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestProgress_Statics::NewProp_QuestCount,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FQuestProgress_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FQuestProgress_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_QuestMapPrototype,
	nullptr,
	&NewStructOps,
	"QuestProgress",
	Z_Construct_UScriptStruct_FQuestProgress_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FQuestProgress_Statics::PropPointers),
	sizeof(FQuestProgress),
	alignof(FQuestProgress),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FQuestProgress_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FQuestProgress_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FQuestProgress()
{
	if (!Z_Registration_Info_UScriptStruct_QuestProgress.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_QuestProgress.InnerSingleton, Z_Construct_UScriptStruct_FQuestProgress_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_QuestProgress.InnerSingleton;
}
// End ScriptStruct FQuestProgress

// Begin Class AQuestMapPlayerController
void AQuestMapPlayerController::StaticRegisterNativesAQuestMapPlayerController()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AQuestMapPlayerController);
UClass* Z_Construct_UClass_AQuestMapPlayerController_NoRegister()
{
	return AQuestMapPlayerController::StaticClass();
}
struct Z_Construct_UClass_AQuestMapPlayerController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "Game/Controller/QuestMapPlayerController.h" },
		{ "ModuleRelativePath", "Game/Controller/QuestMapPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Quests_MetaData[] = {
		{ "Category", "Quest" },
		{ "ModuleRelativePath", "Game/Controller/QuestMapPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Quests_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Quests;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AQuestMapPlayerController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AQuestMapPlayerController_Statics::NewProp_Quests_Inner = { "Quests", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FQuestProgress, METADATA_PARAMS(0, nullptr) }; // 3045942703
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AQuestMapPlayerController_Statics::NewProp_Quests = { "Quests", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AQuestMapPlayerController, Quests), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Quests_MetaData), NewProp_Quests_MetaData) }; // 3045942703
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AQuestMapPlayerController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AQuestMapPlayerController_Statics::NewProp_Quests_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AQuestMapPlayerController_Statics::NewProp_Quests,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AQuestMapPlayerController_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AQuestMapPlayerController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerController,
	(UObject* (*)())Z_Construct_UPackage__Script_QuestMapPrototype,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AQuestMapPlayerController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AQuestMapPlayerController_Statics::ClassParams = {
	&AQuestMapPlayerController::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AQuestMapPlayerController_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AQuestMapPlayerController_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AQuestMapPlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_AQuestMapPlayerController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AQuestMapPlayerController()
{
	if (!Z_Registration_Info_UClass_AQuestMapPlayerController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AQuestMapPlayerController.OuterSingleton, Z_Construct_UClass_AQuestMapPlayerController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AQuestMapPlayerController.OuterSingleton;
}
template<> QUESTMAPPROTOTYPE_API UClass* StaticClass<AQuestMapPlayerController>()
{
	return AQuestMapPlayerController::StaticClass();
}
AQuestMapPlayerController::AQuestMapPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AQuestMapPlayerController);
AQuestMapPlayerController::~AQuestMapPlayerController() {}
// End Class AQuestMapPlayerController

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Game_Controller_QuestMapPlayerController_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EQuestName_StaticEnum, TEXT("EQuestName"), &Z_Registration_Info_UEnum_EQuestName, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1607759001U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FQuestProgress::StaticStruct, Z_Construct_UScriptStruct_FQuestProgress_Statics::NewStructOps, TEXT("QuestProgress"), &Z_Registration_Info_UScriptStruct_QuestProgress, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FQuestProgress), 3045942703U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AQuestMapPlayerController, AQuestMapPlayerController::StaticClass, TEXT("AQuestMapPlayerController"), &Z_Registration_Info_UClass_AQuestMapPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AQuestMapPlayerController), 2210690073U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Game_Controller_QuestMapPlayerController_h_2785374732(TEXT("/Script/QuestMapPrototype"),
	Z_CompiledInDeferFile_FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Game_Controller_QuestMapPlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Game_Controller_QuestMapPlayerController_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Game_Controller_QuestMapPlayerController_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Game_Controller_QuestMapPlayerController_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Game_Controller_QuestMapPlayerController_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Game_Controller_QuestMapPlayerController_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
