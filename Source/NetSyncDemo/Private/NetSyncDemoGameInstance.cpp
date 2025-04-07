// Fill out your copyright notice in the Description page of Project Settings.


#include "NetSyncDemoGameInstance.h"

void UNetSyncDemoGameInstance::OnStart()
{
	Super::OnStart();

	if (bDebugMode)
	{
		GameScript = MakeShared<puerts::FJsEnv>(
			std::make_shared<puerts::DefaultJSModuleLoader>(TEXT("JavaScript")),
			std::make_shared<puerts::FDefaultLogger>(),
			8080);
		if (bWaitForDebugger)
		{
			GameScript->WaitDebugger();
		}
	}
	else
	{
		GameScript = MakeShared<puerts::FJsEnv>();
	}

	TArray<TPair<FString, UObject*>> Arguments;
	Arguments.Add({TEXT("GameInstance"), this});
	
	GameScript->Start("MainGame", Arguments);
}

void UNetSyncDemoGameInstance::Shutdown()
{
	Super::Shutdown();

	GameScript.Reset();
}

void UNetSyncDemoGameInstance::CallTS(FString FunctionName, UObject* InObj)
{
	Call.Execute(FunctionName, InObj);
}
