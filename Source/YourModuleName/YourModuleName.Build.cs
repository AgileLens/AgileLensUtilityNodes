// YourModuleName.Build.cs

using UnrealBuildTool;

public class YourModuleName : ModuleRules
{
    public YourModuleName(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            });
    }
}