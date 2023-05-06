// Fill out your copyright notice in the Description page of Project Settings.


#include "OverheadWidget.h"
#include "Components/TextBlock.h"
#include "GameFramework/PlayerState.h"

void UOverheadWidget::SetDisplayText(FString TextToDisplay)
{
	if (DisplayText)
	{
		DisplayText->SetText(FText::FromString(TextToDisplay));
	}
}

void UOverheadWidget::ShowPlayerName(APawn* InPawn, bool bShowName)
{
	APlayerState* PlayerState = InPawn->GetPlayerState();
	FString PlayerName = FString("");

	if (PlayerState && bShowName)
	{
		PlayerName = PlayerState->GetPlayerName();
	}

	SetDisplayText(*PlayerName);
	
}

void UOverheadWidget::NativeDestruct()
{
	RemoveFromParent();
	Super::NativeDestruct();
}