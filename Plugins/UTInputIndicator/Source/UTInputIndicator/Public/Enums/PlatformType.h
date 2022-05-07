#pragma once

#include "CoreMinimal.h"
#include "PlatformType.generated.h"

/**
 * @brief Different platform types supported by the Input Indicator plugin
 */
UENUM(BlueprintType)
enum class EPlatformType : uint8
{
	PC,
	Xbox,
	Playstation,
	Switch
};