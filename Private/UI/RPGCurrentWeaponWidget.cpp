// Copyright Stanislav Bezrukov. All Rights Reserved.

#include "UI/RPGCurrentWeaponWidget.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Utility/RPGItemHelper.h"
#include "Utility/RPGHelperFunctions.h"
#include "Interfaces/RPGCurrentWeapon.h"

void URPGCurrentWeaponWidget::NativeConstruct()
{
    Super::NativeConstruct();
    IRPGCurrentWeapon* CurrentWeaponComponent = RPGHelperFunctions::GetComponentByInterface<IRPGCurrentWeapon>(GetOwningPlayerPawn());
    check(CurrentWeaponComponent);
    CurrentWeaponComponent->OnCurrentWeaponChanged().AddUObject(this, &ThisClass::UpdateThisWidget);
}

void URPGCurrentWeaponWidget::SetWeapon(const FName& InWeaponRow)
{
    WeaponRowName = InWeaponRow;
    const FRPGItemInfo* ItemInfo = FRPGItemHelper::GetItemInfo(WeaponRowName);
    if (ItemInfo)
    {
        check(DamageTextBlock);
        DamageTextBlock->SetText(FText::Format(FTextFormat::FromString("{0}"), ItemInfo->Damage));
        check(NameTextBlock);
        NameTextBlock->SetText(ItemInfo->Name);
        check(Thumbnail);
        Thumbnail->SetBrushFromTexture(ItemInfo->Thumbnail);
    }
}

void URPGCurrentWeaponWidget::UpdateThisWidget(FName& InNewWeapon)
{
    SetWeapon(InNewWeapon);
}
