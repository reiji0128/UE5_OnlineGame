// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "GameGameMode.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GAME_GameGameMode_generated_h
#error "GameGameMode.generated.h already included, missing '#pragma once' in GameGameMode.h"
#endif
#define GAME_GameGameMode_generated_h

#define FID_Users_reiji_Desktop_UE5_OnlineGame_Game_Source_Game_GameGameMode_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGameGameMode(); \
	friend struct Z_Construct_UClass_AGameGameMode_Statics; \
public: \
	DECLARE_CLASS(AGameGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Game"), GAME_API) \
	DECLARE_SERIALIZER(AGameGameMode)


#define FID_Users_reiji_Desktop_UE5_OnlineGame_Game_Source_Game_GameGameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AGameGameMode(AGameGameMode&&); \
	AGameGameMode(const AGameGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GAME_API, AGameGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGameGameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGameGameMode) \
	GAME_API virtual ~AGameGameMode();


#define FID_Users_reiji_Desktop_UE5_OnlineGame_Game_Source_Game_GameGameMode_h_9_PROLOG
#define FID_Users_reiji_Desktop_UE5_OnlineGame_Game_Source_Game_GameGameMode_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_reiji_Desktop_UE5_OnlineGame_Game_Source_Game_GameGameMode_h_12_INCLASS_NO_PURE_DECLS \
	FID_Users_reiji_Desktop_UE5_OnlineGame_Game_Source_Game_GameGameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAME_API UClass* StaticClass<class AGameGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_reiji_Desktop_UE5_OnlineGame_Game_Source_Game_GameGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
