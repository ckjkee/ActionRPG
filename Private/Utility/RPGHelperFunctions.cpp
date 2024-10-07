// Copyright Stanislav Bezrukov. All Rights Reserved.


#include "Utility/RPGHelperFunctions.h"
#include "GameFramework/InputSettings.h"

FText RPGHelperFunctions::GetDisplayNameByActionName(const FName& ActionName)
{
    check(UInputSettings::GetInputSettings());
    TArray<FInputActionKeyMapping> OutMappings;
    UInputSettings::GetInputSettings()->GetActionMappingByName(ActionName, OutMappings);
    if(OutMappings.Num() > 0)
    {
        return OutMappings[0].Key.GetDisplayName();
    }
    return FText();
}
