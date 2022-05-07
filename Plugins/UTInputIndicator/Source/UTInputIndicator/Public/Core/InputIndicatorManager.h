#pragma once
#include "Structs/InputIndicatorMapping.h"

#include "InputIndicatorManager.generated.h"

/**
 * @brief Responsible for updating all widgets according to the current platform type
 */
UCLASS()
class UTINPUTINDICATOR_API AInputIndicatorManager final : public AActor
{
	GENERATED_BODY()

public:
	/**
	 * @brief An array of all key mappings for the PC platform
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input Indicator")
	TArray<FInputIndicatorMapping> PCInputIndicators;

	/**
	 * @brief An array of all key mappings for the Xbox platform
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input Indicator")
	TArray<FInputIndicatorMapping> XboxInputIndicators;

	/**
	 * @brief An array of all key mappings for the Playstation platform
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input Indicator")
	TArray<FInputIndicatorMapping> PlaystationInputIndicators;

	/**
	 * @brief An array of all key mappings for the Switch platform
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input Indicator")
	TArray<FInputIndicatorMapping> SwitchInputIndicators;
	
protected:
	/**
	 * @brief Overridable native event for when play begins for this actor
	 */
	virtual void BeginPlay() override;

private:
	/**
	 * @brief Update the platform type after a key is pressed
	 * @param Key The key that was pressed
	 */
	void AnyKeyPressed(FKey Key);
};