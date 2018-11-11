// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class CliffHangerServerTarget : TargetRules
{
    public CliffHangerServerTarget(TargetInfo Target) : base (Target)
    {
        Type = TargetType.Server;

        ExtraModuleNames.AddRange(new string[] { "CliffHanger" });
    }
}