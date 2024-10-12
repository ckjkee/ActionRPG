// Copyright Stanislav Bezrukov. All Rights Reserved.


#include "UI/RPGPauseWidget.h"
#include "UI/RPGButtonWidget.h"

void URPGPauseWidget::NativeConstruct()
{
	Super::NativeConstruct();
	check(ContinueButton);
	check(ReturnToMainMenuButton);
	check(QuitGameButton);

	ContinueButton->OnButtonClicked().AddDynamic(this, &ThisClass::OnContinueButtonClicked);
	ReturnToMainMenuButton->OnButtonClicked().AddDynamic(this, &ThisClass::OnReturnToMainMenuButtonClicked);
	QuitGameButton->OnButtonClicked().AddDynamic(this, &ThisClass::OnQuitGameButtonClicked);
}

void URPGPauseWidget::OnContinueButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("OnContinueButtonClicked"));
}

void URPGPauseWidget::OnReturnToMainMenuButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("OnReturnToMainMenuButtonClicked"));
}

void URPGPauseWidget::OnQuitGameButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("OnQuitGameButtonClicked"));
}
