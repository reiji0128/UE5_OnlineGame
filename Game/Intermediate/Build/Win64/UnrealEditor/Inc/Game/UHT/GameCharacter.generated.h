// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "GameCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GAME_GameCharacter_generated_h
#error "GameCharacter.generated.h already included, missing '#pragma once' in GameCharacter.h"
#endif
#define GAME_GameCharacter_generated_h

#define FID_Users_reiji_Desktop_UE5_OnlineGame_Game_Source_Game_GameCharacter_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGameCharacter(); \
	friend struct Z_Construct_UClass_AGameCharacter_Statics; \
public: \
	DECLARE_CLASS(AGameCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Game"), NO_API) \
	DECLARE_SERIALIZER(AGameCharacter)


#define FID_Users_reiji_Desktop_UE5_OnlineGame_Game_Source_Game_GameCharacter_h_21_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AGameCharacter(AGameCharacter&&); \
	AGameCharacter(const AGameCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGameCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGameCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGameCharacter) \
	NO_API virtual ~AGameCharacter();


#define FID_Users_reiji_Desktop_UE5_OnlineGame_Game_Source_Game_GameCharacter_h_18_PROLOG
#define FID_Users_reiji_Desktop_UE5_OnlineGame_Game_Source_Game_GameCharacter_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_reiji_Desktop_UE5_OnlineGame_Game_Source_Game_GameCharacter_h_21_INCLASS_NO_PURE_DECLS \
	FID_Users_reiji_Desktop_UE5_OnlineGame_Game_Source_Game_GameCharacter_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAME_API UClass* StaticClass<class AGameCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_reiji_Desktop_UE5_OnlineGame_Game_Source_Game_GameCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
