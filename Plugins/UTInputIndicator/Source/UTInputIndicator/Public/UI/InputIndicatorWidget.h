#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Structs/InputIndicatorMapping.h"
#include "InputIndicatorWidget.generated.h"

/**
 * @brief Input Indicator Widget that is updated according to the current platform type
 */
UCLASS()
class UTINPUTINDICATOR_API UInputIndicatorWidget final : public UUserWidget
{
	GENERATED_BODY()

public:
	/**
	 * @brief The container for the PC input indicator
	 */
	UPROPERTY(meta = (BindWidget), EditAnywhere, BlueprintReadWrite, Category = "UI")
	class UPanelWidget* PcContainer;

	/**
	 * @brief The container for the Xbox input indicator
	 */
	UPROPERTY(meta = (BindWidget), EditAnywhere, BlueprintReadWrite, Category = "UI")
	class UPanelWidget* XboxContainer;
	
	/**
	 * @brief The container for the Playstation input indicator
	 */
	UPROPERTY(meta = (BindWidget), EditAnywhere, BlueprintReadWrite, Category = "UI")
	class UPanelWidget* PlaystationContainer;

	/**
	 * @brief The container for the Switch input indicator
	 */
	UPROPERTY(meta = (BindWidget), EditAnywhere, BlueprintReadWrite, Category = "UI")
	class UPanelWidget* SwitchContainer;

	/**
	 * @brief The image for the PC input indicator
	 */
	UPROPERTY(meta = (BindWidget), EditAnywhere, BlueprintReadWrite, Category = "UI")
	class UImage* PcImage;

	/**
	 * @brief The image for the Xbox input indicator
	 */
	UPROPERTY(meta = (BindWidget), EditAnywhere, BlueprintReadWrite, Category = "UI")
	class UImage* XboxImage;
	
	/**
	 * @brief The image for the Playstation input indicator
	 */
	UPROPERTY(meta = (BindWidget), EditAnywhere, BlueprintReadWrite, Category = "UI")
	class UImage* PlaystationImage;

	/**
	 * @brief The image for the Switch input indicator
	 */
	UPROPERTY(meta = (BindWidget), EditAnywhere, BlueprintReadWrite, Category = "UI")
	class UImage* SwitchImage;

	/**
	 * @brief The PC key represented in the input indicator
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input Indicator")
	FKey PCKey;

	/**
	 * @brief The Xbox key represented in the input indicator
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input Indicator")
	FKey XboxKey;

	/**
	 * @brief The Playstation key represented in the input indicator
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input Indicator")
	FKey PlaystationKey;

	/**
	 * @brief The Switch key represented in the input indicator
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input Indicator")
	FKey SwitchKey;

	/**
	 * @brief Update the input indicator according to the current platform type
	 */
	void UpdateIndicator() const;

protected:
	/**
	 * @brief Overridable native event for when the widget has been constructed
	 */
	virtual void NativeConstruct() override;

private:
	/**
	 * @brief Get the input indicator image using the specified mappings and key
	 * @param Mappings The array of input indicator mappings
	 * @param Key The key used to retrieve the image from the mappings
	 * @return The input indicator image for the specified key
	 */
	UTexture2D* GetImage(TArray<FInputIndicatorMapping> Mappings, FKey Key);
};