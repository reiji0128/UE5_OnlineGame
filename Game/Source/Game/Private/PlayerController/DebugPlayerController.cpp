// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController/DebugPlayerController.h"
#include "Game/GameMode/OnlineGameMode.h"

void ADebugPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (AGameModeBase* gameModeBase = GetWorld()->GetAuthGameMode<AGameModeBase>())
	{
		if (AOnlineGameMode* onlineMode = Cast<AOnlineGameMode>(gameModeBase))
		{
			InputComponent->BindKey(EKeys::One, IE_Pressed, onlineMode, &AOnlineGameMode::CreateSession);
			InputComponent->BindKey(EKeys::Two, IE_Pressed, onlineMode, &AOnlineGameMode::JoinGameSession);
		}
	}
}