// Fill out your copyright notice in the Description page of Project Settings.


#include "CommonSessionManager.h"
#include "OnlineSubsystem.h"

UCommonSessionManager::UCommonSessionManager()
{
}

//void UCommonSessionManager::ShowNetworkConnectDebugMessage()
//{
//	bool bIsGetSessionInterface = false;
//
//	IOnlineSubsystem* onlineSubsystem = IOnlineSubsystem::Get();
//	if (onlineSubsystem)
//	{
//		OnlineSessionInterface = onlineSubsystem->GetSessionInterface();
//		if (OnlineSessionInterface)
//		{
//			bIsGetSessionInterface = true;
//		}
//	}
//
//	if (bIsGetSessionInterface)
//	{
//		if (GEngine)
//		{
//			GEditor->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString::Printf(TEXT("Found Subsystem %s"), *onlineSubsystem->GetSubsystemName().ToString()));
//		}
//	}
//	else
//	{
//		if (GEngine)
//		{
//			GEditor->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, TEXT("Not Found Subsystem"));
//		}
//	}
//}
