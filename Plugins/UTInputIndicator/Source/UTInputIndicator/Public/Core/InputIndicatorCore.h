#pragma once

#include "CoreMinimal.h"
#include "Enums/PlatformType.h"
#include "Structs/InputIndicatorMapping.h"

/**
 * @brief Responsible for managing the current platform type and all the input indicator mappings
 */
class UTINPUTINDICATOR_API FInputIndicatorCore
{
public:
	/**
	 * @brief An array of all key mappings for the PC platform
	 */
	static TArray<FInputIndicatorMapping> PCInputIndicators;
	
	/**
	 * @brief An array of all key mappings for the Xbox platform 
	 */
	static TArray<FInputIndicatorMapping> XboxInputIndicators;
	
	/**
	 * @brief An array of all key mappings for the Playstation platform
	 */
	static TArray<FInputIndicatorMapping> PlaystationInputIndicators;
	
	/**
	 * @brief An array of all key mappings for the Switch platform
	 */
	static TArray<FInputIndicatorMapping> SwitchInputIndicators;
	
	/**
	 * @brief Update the platform type based on the type of input used (PC Only)
	 * @param WorldContext The world context
	 * @param IsControllerKey A boolean value indicating if the key that was pressed is from a controller
	 */
	static void UpdatePlatformType(UWorld* WorldContext, bool IsControllerKey);
	
	/**
	 * @brief Get the current platform type
	 * @return The current platform type
	 */
	static EPlatformType GetPlatformType();

private:
	/**
	 * @brief The current platform type
	 */
	static EPlatformType PlatformType;
	
	/**
	 * @brief A boolean value indicating if the platform type was previously defined
	 */
	static bool PlatformTypeDefined;

	/**
	 * @brief Get a string representing the current platform type
	 * @return A string representing the current platform type
	 */
	static FString GetPlatformTypeString();
};