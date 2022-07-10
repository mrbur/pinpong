// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/PlayerStart.h"
#include "pingpongGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class PINGPONG_API ApingpongGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
protected:
	UPROPERTY()
	class APingPongPlayerController* Player1 = NULL;
	UPROPERTY()
	class APingPongPlayerController* Player2 = NULL;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	APlayerStart* Player1Start;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	APlayerStart* Player2Start;
public:
	ApingpongGameModeBase();
	virtual void BeginPlay() override;
	virtual void PostLogin(APlayerController* NewPlayer) override;
};
