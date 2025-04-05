// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/GameInstance/OnlineGameInstance.h"
#include "OnlineSubsystem.h"
#include "steam\steam_api.h"

void UOnlineGameInstance::Init()
{
	if (SteamAPI_Init())
	{
		UE_LOG(LogTemp, Log, TEXT("Steam API Initialize"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Steam API Initialization Failed"));
	}

	IOnlineSubsystem* OnlineSubsystem = IOnlineSubsystem::Get();

	if (OnlineSubsystem)
	{
		OnlineSessionInterface = OnlineSubsystem->GetSessionInterface();

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("Found subsystem %s"), *OnlineSubsystem->GetSubsystemName().ToString()));
		}
	}
}
