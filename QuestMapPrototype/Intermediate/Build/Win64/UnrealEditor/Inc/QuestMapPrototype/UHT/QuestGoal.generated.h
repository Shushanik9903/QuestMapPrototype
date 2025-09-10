// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Quests/QuestGoal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef QUESTMAPPROTOTYPE_QuestGoal_generated_h
#error "QuestGoal.generated.h already included, missing '#pragma once' in QuestGoal.h"
#endif
#define QUESTMAPPROTOTYPE_QuestGoal_generated_h

#define FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Quests_QuestGoal_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUQuestGoal(); \
	friend struct Z_Construct_UClass_UQuestGoal_Statics; \
public: \
	DECLARE_CLASS(UQuestGoal, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/QuestMapPrototype"), NO_API) \
	DECLARE_SERIALIZER(UQuestGoal)


#define FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Quests_QuestGoal_h_23_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UQuestGoal(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UQuestGoal(UQuestGoal&&); \
	UQuestGoal(const UQuestGoal&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UQuestGoal); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UQuestGoal); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UQuestGoal) \
	NO_API virtual ~UQuestGoal();


#define FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Quests_QuestGoal_h_20_PROLOG
#define FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Quests_QuestGoal_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Quests_QuestGoal_h_23_INCLASS_NO_PURE_DECLS \
	FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Quests_QuestGoal_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> QUESTMAPPROTOTYPE_API UClass* StaticClass<class UQuestGoal>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_gevor_OneDrive_Desktop_QuestMapPrototype_QuestMapPrototype_Source_QuestMapPrototype_Quests_QuestGoal_h


#define FOREACH_ENUM_EGOALTYPE(op) \
	op(EGoalType::Static) \
	op(EGoalType::Dynamic) 

enum class EGoalType : uint8;
template<> struct TIsUEnumClass<EGoalType> { enum { Value = true }; };
template<> QUESTMAPPROTOTYPE_API UEnum* StaticEnum<EGoalType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
