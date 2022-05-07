#include "UI/InputIndicatorWidget.h"

#include "Components/Image.h"
#include "Core/InputIndicatorCore.h"
#include "Core/Log.h"
#include "Enums/PlatformType.h"

/**
 * @brief Overridable native event for when the widget has been constructed
 */
void UInputIndicatorWidget::NativeConstruct()
{
	Super::NativeConstruct();
	UpdateIndicator();
	
	PcImage->SetBrushFromTexture(GetImage(FInputIndicatorCore::PCInputIndicators, PCKey));
	XboxImage->SetBrushFromTexture(GetImage(FInputIndicatorCore::XboxInputIndicators, XboxKey));
	PlaystationImage->SetBrushFromTexture(GetImage(FInputIndicatorCore::PlaystationInputIndicators, PlaystationKey));
	SwitchImage->SetBrushFromTexture(GetImage(FInputIndicatorCore::SwitchInputIndicators, SwitchKey));
	ULog::Trace("InputIndicatorWidget::NativeConstruct", "Input indicator widget initialized");
}

/**
 * @brief Update the input indicator according to the current platform type
 */
void UInputIndicatorWidget::UpdateIndicator() const
{
	ULog::Info("InputIndicatorWidget::UpdateIndicator", "Updating input indicator");
	const EPlatformType Platform = FInputIndicatorCore::GetPlatformType(); 
	PcContainer->SetVisibility(Platform == EPlatformType::PC ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
	XboxContainer->SetVisibility(Platform == EPlatformType::Xbox ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
	PlaystationContainer->SetVisibility(Platform == EPlatformType::Playstation ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
	SwitchContainer->SetVisibility(Platform == EPlatformType::Switch ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
	ULog::Info("InputIndicatorWidget::UpdateIndicator", "Input indicator updated");
}

/**
 * @brief Get the input indicator image using the specified mappings and key
 * @param Mappings The array of input indicator mappings
 * @param Key The key used to retrieve the image from the mappings
 * @return The input indicator image for the specified key
 */
UTexture2D* UInputIndicatorWidget::GetImage(TArray<FInputIndicatorMapping> Mappings, const FKey Key)
{
	for (FInputIndicatorMapping Mapping : Mappings)
	{
		if (Mapping.Key == Key)
		{
			ULog::Info("InputIndicatorWidget::GetImage", "Input indicator image found for " + Key.GetDisplayName().ToString());
			return Mapping.Image;
		}
	}

	ULog::Error("InputIndicatorWidget::GetImage", "Input indicator image not found for " + Key.GetDisplayName().ToString());
	return nullptr;
}