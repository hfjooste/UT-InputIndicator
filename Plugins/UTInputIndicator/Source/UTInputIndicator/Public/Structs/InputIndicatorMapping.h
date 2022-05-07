#pragma once

#include "Runtime/UMG/Public/UMG.h"
#include "CoreMinimal.h"
#include "InputIndicatorMapping.generated.h"

/**
 * @brief Map keys to the image that needs to be displayed
 */
USTRUCT(BlueprintType)
struct UTINPUTINDICATOR_API FInputIndicatorMapping
{
	GENERATED_BODY()

public:
	/**
	 * @brief The key that needs to be mapped to an image
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input Indicator")
	FKey Key;

	/**
	 * @brief The image that will be displayed for the specified key
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input Indicator")
	UTexture2D* Image;
};