// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/GameMode/OnlineGameMode.h"
#include "Game/GameInstance/OnlineGameInstance.h"
#include "PlayerController/DebugPlayerController.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "OnlineSessionSettings.h"
#include "Online/OnlineSessionNames.h"
#include "OnlineSubsystemTypes.h"
#include "../GameCharacter.h"

AOnlineGameMode::AOnlineGameMode()
{
	DefaultPawnClass = AGameCharacter::StaticClass();
	PlayerControllerClass = ADebugPlayerController::StaticClass();

	CreateSessionCompleteDelegate = FOnCreateSessionCompleteDelegate::CreateUObject(this, &ThisClass::OnCreateSessionComplete);
	FindSessionCompleteDelegate   = FOnFindSessionsCompleteDelegate::CreateUObject(this, &ThisClass::OnFindSessionComplete);
	JoinSessionCompleteDelegate   = FOnJoinSessionCompleteDelegate::CreateUObject(this, &ThisClass::OnJoinSessionComplete);
}

void AOnlineGameMode::BeginPlay()
{
}

void AOnlineGameMode::CreateSession()
{
	UOnlineGameInstance* gameInstance = Cast<UOnlineGameInstance>(GetWorld()->GetGameInstance());
	IOnlineSessionPtr onlineSessionInterface;
	if (!gameInstance || !(onlineSessionInterface = gameInstance->GetOnlineSessionInterface()))
	{
		UE_LOG(LogTemp, Error, TEXT("[AOnlineGameMode::CreateSession] Create Session Failed."));
		return;
	}
	
	FNamedOnlineSession* existingSession = onlineSessionInterface->GetNamedSession(NAME_GameSession);
	if (existingSession != nullptr)
	{
		onlineSessionInterface->DestroySession(NAME_GameSession);
	}

	onlineSessionInterface->AddOnCreateSessionCompleteDelegate_Handle(CreateSessionCompleteDelegate);

	TSharedPtr<FOnlineSessionSettings> sessionSettings = MakeShareable(new FOnlineSessionSettings());
	sessionSettings->bIsLANMatch = false;
	sessionSettings->NumPublicConnections = 4;
	sessionSettings->bAllowJoinInProgress = true;
	sessionSettings->bAllowJoinViaPresence = true;
	sessionSettings->bShouldAdvertise = true;
	sessionSettings->bUsesPresence = true;
	sessionSettings->bUseLobbiesIfAvailable = true;
	sessionSettings->Set("MatchType", FString("FreeForAll"), EOnlineDataAdvertisementType::ViaOnlineService);

	const ULocalPlayer* localPlayer = GetWorld()->GetFirstLocalPlayerFromController();

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("create")));
	onlineSessionInterface->CreateSession(*localPlayer->GetPreferredUniqueNetId(), NAME_GameSession, *sessionSettings);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("UNetId : %s"), *localPlayer->GetPreferredUniqueNetId()->ToString()));
}

void AOnlineGameMode::JoinGameSession()
{
	UE_LOG(LogTemp, Log, TEXT("[AOnlineGameMode::JoinGameSession]"));
	IOnlineSessionPtr onlineSessionInterface;
	onlineSessionInterface = Cast<UOnlineGameInstance>(GetWorld()->GetGameInstance())->GetOnlineSessionInterface();
	
	if (!onlineSessionInterface.IsValid())
	{
		return;
	}

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("Pressed 2 and Executed function : AOnlineGameMode::JoinGameSession()")));
	}

	onlineSessionInterface->AddOnFindSessionsCompleteDelegate_Handle(FindSessionCompleteDelegate);

	SessionSearch = MakeShareable(new FOnlineSessionSearch());
	SessionSearch->MaxSearchResults = 10000;
	SessionSearch->bIsLanQuery = false;
	//SessionSearch->QuerySettings.Set(FName("MatchType"), FString("FreeForAll"), EOnlineComparisonOp::Equals);
	SessionSearch->QuerySettings.Set(SEARCH_PRESENCE, true, EOnlineComparisonOp::Equals);

	const ULocalPlayer* localPlayer = GetWorld()->GetFirstLocalPlayerFromController();
	onlineSessionInterface->FindSessions(*localPlayer->GetPreferredUniqueNetId(), SessionSearch.ToSharedRef());
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("UNetId : %s"), *localPlayer->GetPreferredUniqueNetId()->ToString()));
}

void AOnlineGameMode::OnCreateSessionComplete(FName SessionName, bool bWasSuccessful)
{
	if (bWasSuccessful)
	{
		if(IOnlineSubsystem* subSystem = IOnlineSubsystem::Get())
		{
			if (IOnlineSessionPtr sessionInterface = subSystem->GetSessionInterface())
			{
				ULocalPlayer* localPlayer = GetWorld()->GetFirstLocalPlayerFromController();
				if (localPlayer && localPlayer->GetPreferredUniqueNetId().IsValid())
				{
					sessionInterface->RegisterPlayer(SessionName, *localPlayer->GetPreferredUniqueNetId(), false);
				}
			}
		}

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("Successfully Created Session %s"), *SessionName.ToString()));
		}

		UWorld* world = GetWorld();
		if (world)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("Level : /Game/Content/Level/Test/TestLobby")));
			world->ServerTravel(FString("/Game/Level/Test/TestLobby?Listen"));
		}
	}
	else
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("Failed to Create Session! : %s"), *SessionName.ToString()));
		}
	}
}

void AOnlineGameMode::OnFindSessionComplete(bool bWasSuccessful)
{
	UE_LOG(LogTemp, Log, TEXT("[FSessionsOSSAdapter::FindSessionsImpl]"));
	IOnlineSessionPtr onlineSessionInterface;
	onlineSessionInterface = Cast<UOnlineGameInstance>(GetWorld()->GetGameInstance())->GetOnlineSessionInterface();

	if (!onlineSessionInterface.IsValid())
	{
		return;
	}

	if (bWasSuccessful)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("FindSession Complete SearchResults.Num() = %d"), SessionSearch->SearchResults.Num()));
		}

		for (auto result : SessionSearch->SearchResults)
		{
			FString id = result.GetSessionIdStr();
			FString user = result.Session.OwningUserName;
			FString matchType = "";
			result.Session.SessionSettings.Get(FName("MatchType"), matchType);

			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, FString::Printf(TEXT("Successfully Find Session Id : %s,OwningUser : %s"), *id, *user));
			}

			if (matchType == FString("FreeForAll"))
			{
				if (GEngine)
				{
					GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, FString::Printf(TEXT("Joining Match Type : %s"), *matchType));
				}
				onlineSessionInterface->AddOnJoinSessionCompleteDelegate_Handle(JoinSessionCompleteDelegate);

				const ULocalPlayer* localPlayer = GetWorld()->GetFirstLocalPlayerFromController();
				onlineSessionInterface->JoinSession(*localPlayer->GetPreferredUniqueNetId(), NAME_GameSession, result);
			}
		}
	}
}

void AOnlineGameMode::OnJoinSessionComplete(FName InSessionName,EOnJoinSessionCompleteResult::Type InResult)
{
	IOnlineSessionPtr onlineSessionInterface;
	onlineSessionInterface = Cast<UOnlineGameInstance>(GetWorld()->GetGameInstance())->GetOnlineSessionInterface();

	if (!onlineSessionInterface.IsValid())
	{
		return;
	}

	FString addres = "";
	if (onlineSessionInterface->GetResolvedConnectString(NAME_GameSession, addres))
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("Connect string Addres : %s"), *addres));
		}

		APlayerController* playerController = GetGameInstance()->GetFirstLocalPlayerController();
		if (playerController)
		{
			playerController->ClientTravel(addres, ETravelType::TRAVEL_Absolute);
		}
	}
}
