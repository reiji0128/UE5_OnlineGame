// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Interfaces\OnlineSessionInterface.h"
#include "OnlineGameInstance.generated.h"
/**
 * 
 */
UCLASS()
class GAME_API UOnlineGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:

	virtual void Init() override;

	IOnlineSessionPtr GetOnlineSessionInterface() const { return OnlineSessionInterface; }

private:
	IOnlineSessionPtr OnlineSessionInterface = nullptr;
};
