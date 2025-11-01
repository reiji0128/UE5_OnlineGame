// Fill out your copyright notice in the Description page of Project Settings.


#include "CommonSessionSubsystem.h"
#include "OnlineSubsystem.h"
#include "Engine/Engine.h"

UCommonSessionSubsystem::UCommonSessionSubsystem()
{
	//ShowNetworkConnectDebugMessage();
}

void UCommonSessionSubsystem::CreateGameSession()
{
}

void UCommonSessionSubsystem::OnCreateSessionComplete()
{
}

void UCommonSessionSubsystem::ShowNetworkConnectDebugMessage()
{
	bool bIsGetSessionInterface = false;

	IOnlineSubsystem* onlineSubsystem = IOnlineSubsystem::Get();
	if (onlineSubsystem)
	{
		OnlineSessionInterface = onlineSubsystem->GetSessionInterface();
		if (OnlineSessionInterface)
		{
			bIsGetSessionInterface = true;
		}
	}

	if (bIsGetSessionInterface)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString::Printf(TEXT("Found Subsystem %s"), *onlineSubsystem->GetSubsystemName().ToString()));
		}
	}
	else
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, TEXT("Not Found Subsystem"));
		}
	}
}
