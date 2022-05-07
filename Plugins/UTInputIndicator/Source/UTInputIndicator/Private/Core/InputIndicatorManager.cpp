#include "Core/InputIndicatorManager.h"

#include "Core/InputIndicatorCore.h"
#include "Core/Log.h"

/**
 * @brief Overridable native event for when play begins for this actor
 */
void AInputIndicatorManager::BeginPlay()
{
	Super::BeginPlay();
	
	FInputIndicatorCore::PCInputIndicators = PCInputIndicators;
	FInputIndicatorCore::XboxInputIndicators = XboxInputIndicators;
	FInputIndicatorCore::PlaystationInputIndicators = PlaystationInputIndicators;
	FInputIndicatorCore::SwitchInputIndicators = SwitchInputIndicators;

	if (InputComponent == nullptr)
	{
		ULog::Error("InputIndicatorManager::BeginPlay", "InputComponent is nullptr");
		return;
	}

	FInputKeyBinding AnyKeyBinding = FInputKeyBinding(FInputChord(EKeys::AnyKey), EInputEvent::IE_Pressed);
	AnyKeyBinding.bConsumeInput = false;
	AnyKeyBinding.bExecuteWhenPaused = true;
	AnyKeyBinding.KeyDelegate.BindDelegate(this, &AInputIndicatorManager::AnyKeyPressed);
	InputComponent->KeyBindings.Add(AnyKeyBinding);

	ULog::Info("InputIndicatorManager::BeginPlay", "Any key binding added");
}

/**
 * @brief Update the platform type after a key is pressed
 * @param Key The key that was pressed
 */
void AInputIndicatorManager::AnyKeyPressed(const FKey Key)
{
	FInputIndicatorCore::UpdatePlatformType(GetWorld(), Key.IsGamepadKey());
}