// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "UI/RPGDamageMessagesWidget.h"
#include "Components/PanelWidget.h"
#include "Interfaces/RPGHealth.h"
#include "Interfaces/RPGCurrentWeapon.h"
#include "UI/RPGDamageMessageWidget.h"

void URPGDamageMessagesWidget::SetPlayerHealthComponent(IRPGHealth* InHealth)
{
    check(InHealth);
    PlayerHealh = InHealth;
    PlayerHealh->OnHealthReduced().AddUObject(this, &ThisClass::OnDamageTaken);
}

void URPGDamageMessagesWidget::SetPlayerCurrentWeaponComponent(IRPGCurrentWeapon* InCurrentWeapon)
{
    check(InCurrentWeapon);
    PlayerCurrentWeapon = InCurrentWeapon;
    PlayerCurrentWeapon->OnDealDamage().AddUObject(this, &ThisClass::OnDealDamage);
}

void URPGDamageMessagesWidget::OnDealDamage(const float InDamage)
{
    CreateDamageMessageWidget(InDamage);
}

void URPGDamageMessagesWidget::OnDamageTaken(const float InDamage)
{
    CreateDamageMessageWidget(-1 * InDamage);
}

void URPGDamageMessagesWidget::CreateDamageMessageWidget(const float InDamage)
{
    check(DamageMessageClass);
    URPGDamageMessageWidget* MessageWidget = CreateWidget<URPGDamageMessageWidget>(this, DamageMessageClass);
    check(MessageWidget);
    if (InDamage > 0)
    {
        MessageWidget->SetDamageDealtNumbers(InDamage);
    }
    else
    {
        MessageWidget->SetDamageTakenNumbers(InDamage);
    }

    PanelWidget->AddChild(MessageWidget);
}
