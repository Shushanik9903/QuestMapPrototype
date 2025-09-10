// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Game/Controller/QuestMapPlayerController.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef QUESTMAPPROTOTYPE_QuestMapPlayerController_generated_h
#error "QuestMapPlayerController.generated.h already included, missing '#pragma once' in QuestMapPlayerController.h"
#endif
#define QUESTMAPPROTOTYPE_QuestMapPlayerController_generated_h

#define FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Game_Controller_QuestMapPlayerController_h_24_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FQuestProgress_Statics; \
	QUESTMAPPROTOTYPE_API static class UScriptStruct* StaticStruct();


template<> QUESTMAPPROTOTYPE_API UScriptStruct* StaticStruct<struct FQuestProgress>();

#define FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Game_Controller_QuestMapPlayerController_h_38_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAQuestMapPlayerController(); \
	friend struct Z_Construct_UClass_AQuestMapPlayerController_Statics; \
public: \
	DECLARE_CLASS(AQuestMapPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/QuestMapPrototype"), NO_API) \
	DECLARE_SERIALIZER(AQuestMapPlayerController)


#define FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Game_Controller_QuestMapPlayerController_h_38_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AQuestMapPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AQuestMapPlayerController(AQuestMapPlayerController&&); \
	AQuestMapPlayerController(const AQuestMapPlayerController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AQuestMapPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AQuestMapPlayerController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AQuestMapPlayerController) \
	NO_API virtual ~AQuestMapPlayerController();


#define FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Game_Controller_QuestMapPlayerController_h_35_PROLOG
#define FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Game_Controller_QuestMapPlayerController_h_38_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Game_Controller_QuestMapPlayerController_h_38_INCLASS_NO_PURE_DECLS \
	FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Game_Controller_QuestMapPlayerController_h_38_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> QUESTMAPPROTOTYPE_API UClass* StaticClass<class AQuestMapPlayerController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Game_Controller_QuestMapPlayerController_h


#define FOREACH_ENUM_EQUESTNAME(op) \
	op(EQuestName::Banana) \
	op(EQuestName::Strawberry) \
	op(EQuestName::Orange) 

enum class EQuestName : uint8;
template<> struct TIsUEnumClass<EQuestName> { enum { Value = true }; };
template<> QUESTMAPPROTOTYPE_API UEnum* StaticEnum<EQuestName>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
