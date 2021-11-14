// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterShooterGameMode.h"

#include "Kismet/GameplayStatics.h"

void AMonsterShooterGameMode::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(CountDownTimerHandle, this,
		&AMonsterShooterGameMode::CountDownTimer, 1.0f, true, 1.0f);
}

void AMonsterShooterGameMode::RestartGameplay(bool Won)
{
	if(Won)
	{
		ResetLevel();
	}
	else
	{
		FTimerHandle TimerHandle;
		GetWorldTimerManager().SetTimer(TimerHandle, this,
			&AMonsterShooterGameMode::ResetLevel, 3.0f);
	}
}


void AMonsterShooterGameMode::ResetLevel()
{
	UGameplayStatics::OpenLevel(GetWorld(), "Gameplay");
}

void AMonsterShooterGameMode::CountDownTimer()
{
	TimerCount--;

	if(TimerCount == 0)
	{
		GetWorldTimerManager().ClearTimer(CountDownTimerHandle);
		ResetLevel();
	}
}
