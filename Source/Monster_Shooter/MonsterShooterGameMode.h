// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MonsterShooterGameMode.generated.h"

/**
 * 
 */
UCLASS()
class MONSTER_SHOOTER_API AMonsterShooterGameMode : public AGameMode
{
	GENERATED_BODY()

public:

	void RestartGameplay(bool Won);

	UPROPERTY(BlueprintReadOnly)
	int TimerCount = 300;

	void BeginPlay() override;

private:

	void ResetLevel();
	
	FTimerHandle CountDownTimerHandle = FTimerHandle();
	
	void CountDownTimer();
};
