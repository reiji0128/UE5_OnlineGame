// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class Game : ModuleRules
{
	public Game(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "OnlineSubsystemSteam","OnlineSubsystem" });

        // Steamworks SDKのパスを設定
        string SteamSDKPath = Path.Combine(ModuleDirectory, "C:/Program Files/Epic Games/UE_5.4/Engine/Source/ThirdParty/Steamworks/Steamv157/sdk");

        // Steamworks SDKのヘッダーファイルへのインクルードパスを追加
        PublicIncludePaths.Add(Path.Combine(SteamSDKPath, "public"));

        // ライブラリのパスを追加
        string SteamLibPath = Path.Combine(SteamSDKPath, "redistributable_bin/win64");
        PublicAdditionalLibraries.Add(Path.Combine(SteamLibPath, "steam_api64.lib"));

        // steam_api.dll を実行時にコピー
        string SteamDllPath = Path.Combine(SteamLibPath, "steam_api.dll");
        RuntimeDependencies.Add(SteamDllPath);
    }
}
