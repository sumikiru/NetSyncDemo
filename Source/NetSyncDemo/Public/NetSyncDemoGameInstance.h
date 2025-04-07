// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "JsEnv.h"
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "NetSyncDemoGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class NETSYNCDEMO_API UNetSyncDemoGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void OnStart() override;
	virtual void Shutdown() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
	bool bDebugMode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
	bool bWaitForDebugger;

	DECLARE_DYNAMIC_DELEGATE_TwoParams(FCall, FString, FunctionName, UObject*, InObj);
	UPROPERTY()
	FCall Call;

	UFUNCTION(BlueprintCallable)
	void CallTS(FString FunctionName, UObject* InObj);
	
private:
	TSharedPtr<puerts::FJsEnv> GameScript;
};
