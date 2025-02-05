// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/GameGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
GAME_API UClass* Z_Construct_UClass_AGameGameMode();
GAME_API UClass* Z_Construct_UClass_AGameGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_Game();
// End Cross Module References

// Begin Class AGameGameMode
void AGameGameMode::StaticRegisterNativesAGameGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AGameGameMode);
UClass* Z_Construct_UClass_AGameGameMode_NoRegister()
{
	return AGameGameMode::StaticClass();
}
struct Z_Construct_UClass_AGameGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "GameGameMode.h" },
		{ "ModuleRelativePath", "GameGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGameGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AGameGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_Game,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGameGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AGameGameMode_Statics::ClassParams = {
	&AGameGameMode::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGameGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AGameGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AGameGameMode()
{
	if (!Z_Registration_Info_UClass_AGameGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGameGameMode.OuterSingleton, Z_Construct_UClass_AGameGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AGameGameMode.OuterSingleton;
}
template<> GAME_API UClass* StaticClass<AGameGameMode>()
{
	return AGameGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AGameGameMode);
AGameGameMode::~AGameGameMode() {}
// End Class AGameGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_reiji_Desktop_UE5_OnlineGame_Game_Source_Game_GameGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AGameGameMode, AGameGameMode::StaticClass, TEXT("AGameGameMode"), &Z_Registration_Info_UClass_AGameGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGameGameMode), 682211838U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_reiji_Desktop_UE5_OnlineGame_Game_Source_Game_GameGameMode_h_2713456077(TEXT("/Script/Game"),
	Z_CompiledInDeferFile_FID_Users_reiji_Desktop_UE5_OnlineGame_Game_Source_Game_GameGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_reiji_Desktop_UE5_OnlineGame_Game_Source_Game_GameGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
