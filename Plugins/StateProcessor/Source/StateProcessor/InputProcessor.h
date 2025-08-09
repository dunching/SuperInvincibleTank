// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include <atomic>
#include <functional>

#include "CoreMinimal.h"

#include "Tools.h"

struct FInputKeyEventArgs;

class FViewport;
class APawn;
class UInputProcessorSubSystemBase;

class STATEPROCESSOR_API FInputProcessor
{
	friend UInputProcessorSubSystemBase;
	
public:

	GENERATIONCLASSINFOONLYTHIS(FInputProcessor);

	using FOnQuitComplete = std::function<void()>;

	using FOnQuitFunc = std::function<void()>;

	FInputProcessor();

	virtual ~FInputProcessor();

	FInputProcessor(const FInputProcessor&) = delete;

	FInputProcessor(FInputProcessor&&) = delete;

	FInputProcessor& operator=(const FInputProcessor&) = delete;

	FInputProcessor& operator=(FInputProcessor&&) = delete;

	// 
	virtual void EnterAction();

	// 
	virtual void ReEnterAction();

	// 
	virtual void QuitAction();

	// 
	virtual void BeginDestroy();

	void GameDown();
	
	virtual bool InputKey(
		const FInputKeyEventArgs& EventArgs
	) ;

	virtual bool InputAxis(
		const FInputKeyEventArgs& EventArgs 
		) ;

    bool GetIsComplete()const;

	bool GetIsRequestQuit()const;

	void UnRegisterTicker();

	void SetOnQuitFunc(const FOnQuitFunc& InOnQuitFunc);
	
protected:

	void IncreaseAsyncTaskNum();
	
	void ReduceAsyncTaskNum();

	virtual void TickImp(float Delta);

	void SwitchShowCursor(bool bIsShowCursor);

private:

	bool Tick(float Delta);

    std::atomic<bool>bIsRequestQuit = false;

	std::atomic<uint8>AsyncTaskNum = 0;

	const float Frequency = 1.f / 60;

	FTSTicker::FDelegateHandle TickDelegateHandle;

	FOnQuitFunc OnQuitFunc;
};
