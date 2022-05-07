#include "Core/InputIndicatorCore.h"

#include "Blueprint/WidgetBlueprintLibrary.h"
#include "UI/InputIndicatorWidget.h"
#include "Core/Log.h"

TArray<FInputIndicatorMapping> FInputIndicatorCore::PCInputIndicators;
TArray<FInputIndicatorMapping> FInputIndicatorCore::XboxInputIndicators;
TArray<FInputIndicatorMapping> FInputIndicatorCore::PlaystationInputIndicators;
TArray<FInputIndicatorMapping> FInputIndicatorCore::SwitchInputIndicators;
bool FInputIndicatorCore::PlatformTypeDefined = false;

#if PLATFORM_XBOXONE
EPlatformType FInputIndicatorCore::PlatformType = EPlatformType::XBOX;
#elif PLATFORM_PS4
EPlatformType FInputIndicatorCore::PlatformType = EPlatformType::PLAYSTATION;
#elif PLATFORM_SWITCH
EPlatformType FInputIndicatorCore::PlatformType = EPlatformType::SWITCH;
#else
EPlatformType FInputIndicatorCore::PlatformType = EPlatformType::PC;
#endif

/**
 * @brief Update the platform type based on the type of input used (PC Only)
 * @param WorldContext The world context
 * @param IsControllerKey A boolean value indicating if the key that was pressed is from a controller
 */
void FInputIndicatorCore::UpdatePlatformType(UWorld* WorldContext, bool IsControllerKey)
{
	const EPlatformType CurrentPlatformType = PlatformType;
	
#if PLATFORM_XBOXONE
	PlatformType = EPlatformType::XBOX;
#elif PLATFORM_PS4
	PlatformType = EPlatformType::PLAYSTATION;
#elif PLATFORM_SWITCH
	PlatformType = EPlatformType::SWITCH;
#else
	PlatformType = IsControllerKey ? EPlatformType::Xbox : EPlatformType::PC;
#endif

	if (CurrentPlatformType != PlatformType || !PlatformTypeDefined)
	{
		PlatformTypeDefined = true;
		ULog::Info("InputIndicatorCore::UpdatePlatformType", "Platform type updated: " + GetPlatformTypeString());
	}

	TArray<UUserWidget*> Widgets;
	UWidgetBlueprintLibrary::GetAllWidgetsOfClass(WorldContext, Widgets, UInputIndicatorWidget::StaticClass(), false);

	for (UUserWidget* Widget : Widgets)
	{
		const UInputIndicatorWidget* InputIndicator = dynamic_cast<UInputIndicatorWidget*>(Widget);
		if (InputIndicator == nullptr)
		{
			continue;
		}

		ULog::Info("InputIndicatorCore::UpdatePlatformType", "Updating input indicator");
		InputIndicator->UpdateIndicator();
	}
}

/**
 * @brief Get the current platform type
 * @return The current platform type
 */
EPlatformType FInputIndicatorCore::GetPlatformType()
{
	return PlatformType;
}

/**
 * @brief Get a string representing the current platform type
 * @return A string representing the current platform type
 */
FString FInputIndicatorCore::GetPlatformTypeString()
{
	FString PlatformTypeString = "Unknown";
	switch (PlatformType)
	{
	case EPlatformType::PC:
		return "PC";
	case EPlatformType::Xbox:
		return "Xbox";
	case EPlatformType::Playstation:
		return "Playstation";
	case EPlatformType::Switch:
		return "Switch";
	default:
		ULog::Error("InputIndicatorCore::GetPlatformTypeString", "Unknown platform type");
		return "Unknown";
	}
}