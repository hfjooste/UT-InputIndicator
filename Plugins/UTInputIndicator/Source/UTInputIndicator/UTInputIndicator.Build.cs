using UnrealBuildTool;

public class UTInputIndicator : ModuleRules
{
	public UTInputIndicator(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicIncludePaths.AddRange(new string[] { });
		PrivateIncludePaths.AddRange(new string[] { });
		PublicDependencyModuleNames.AddRange(new string[] {"Core", "InputCore", "UMG", "Slate", "SlateCore", "UTLogger"});
		PrivateDependencyModuleNames.AddRange(new string[] {"CoreUObject", "Engine", "InputCore", "UMG", "Slate", "SlateCore", "UTLogger"});
		DynamicallyLoadedModuleNames.AddRange(new string[] { });
	}
}
