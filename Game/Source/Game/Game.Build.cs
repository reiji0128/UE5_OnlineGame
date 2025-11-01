// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class Game : ModuleRules
{
	public Game(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "OnlineSubsystemSteam","OnlineSubsystem", "OnlineSubsystemUtils" });

        // Steamworks SDKのパスを設定
        string SteamSDKPath = Path.Combine(ModuleDirectory, "C:/Program Files/Epic Games/UE_5.4/Engine/Source/ThirdParty/Steamworks/Steamv157/sdk");

        // Steamworks SDKのヘッダーファイルへのインクルードパスを追加
        PublicIncludePaths.Add(Path.Combine(SteamSDKPath, "public"));

        // ライブラリのパスを追加
        string SteamLibPath = Path.Combine(SteamSDKPath, "redistributable_bin/win64");
        PublicAdditionalLibraries.Add(Path.Combine(SteamLibPath, "steam_api64.lib"));

        // steam_api.dll を実行時にコピー
        string SteamDllPath = Path.Combine(SteamLibPath, "steam_api64.dll");
        RuntimeDependencies.Add(SteamDllPath);

        // Steam App ID のコピー設定
        //string sourcePath = @"C:/Users/reiji/Desktop/UE5_OnlineGame/Game/Config/steam_appid.txt"; 
        string sourcePath = Path.Combine("C:", "Users", "reiji", "Desktop", "UE5_OnlineGame", "Game", "Config", "steam_appid.txt");
        // Binaries/Win64 にコピー
        RuntimeDependencies.Add("$(TargetOutputDir)/steam_appid.txt", sourcePath);
        //RuntimeDependencies.Add("$(ProjectDir)/steam_appid.txt");
    }
}
