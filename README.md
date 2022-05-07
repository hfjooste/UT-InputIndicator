# Input Indicators Plugin

The Input Indicators Plugin for Unreal Engine allows you to easily create widgets that display the controls to the user. It automatically changes based on the current input device and support the following devices:
1. Keyboard/Mouse
2. Controller on PC (using the Xbox indicators)
3. Xbox Series X|S Controller
4. Playstation 5 Controller
5. Nintendo Switch Controller

## Installation
1. Download the latest release from GitHub
2. Navigate to `C:\Program Files\Epic Games\UE_{VERSION}\Engine\Plugins\`
3. Create a `Marketplace` folder if needed
4. Extract the release and copy to the `Marketplace` folder
5. Open Unreal Engine
6. Click on `Edit > Plugins`
7. Enable the plugin under the `Installed > Unreal Toolbox` category
8. Restart Unreal Engine

## Input Indicator Manager
Each map need to contain an instance of the `Input Indicator Manager`. This can be done by placing the `Input Indicator Manager Instance` anywhere in the current map. The `Input Indicator Manager` contains 4 properties that is used to set the widget images:
1. `PC Input Indicators` - A list of all supported keyboard/mouse keys and the image used for each key
2. `Xbox Input Indicators` - A list of all supported Xbox keys and the image used for each key
3. `Playstation Input Indicators` - A list of all supported Playstation keys and the image used for each key
4. `Switch Input Indicators` - A list of all supported Nintendo Switch keys and the image used for each key

The `Input Indicator Manager Instance` already contains all the indicators needed for the game but can easily be modified if needed.

## Input Indicator Widget
After installing and enabling the plugin, you should see a new `Input Indicator Widget` item in the palette when creating widgets. There is 4 properties that you need to set on each `Input Indicator Widget`
1. `PCKey` - The key binding used on keyboard/mouse input devices
2. `XboxKey` - The key binding used on a Xbox controller (or any controller on a PC)
3. `PlaystationKey` - The key binding used on a Playstation controller
4. `SwitchKey` - The key binding used on a Nintendo Switch

The input indicator will automatically retrieve the correct image from the `Input Indicator Manager` based on the specified keys. It will also update the images automatically when switching input devices

## Special Thanks
All input indicator images were designed by Nicolae (Xelu) Berbece. Show them some love [@xelubest](https://twitter.com/xelubest)