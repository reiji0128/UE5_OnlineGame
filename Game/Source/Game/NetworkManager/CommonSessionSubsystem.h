// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "CommonSessionSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class GAME_API UCommonSessionSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:

	UCommonSessionSubsystem();

	void CreateGameSession();

	void OnCreateSessionComplete();

private:

	void ShowNetworkConnectDebugMessage();

	IOnlineSessionPtr OnlineSessionInterface;
};
