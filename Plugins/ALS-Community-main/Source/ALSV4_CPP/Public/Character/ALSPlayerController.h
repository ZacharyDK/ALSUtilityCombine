// Project:         Advanced Locomotion System V4 on C++
// Copyright:       Copyright (C) 2021 Doğa Can Yanıkoğlu
// License:         MIT License (http://www.opensource.org/licenses/mit-license.php)
// Source Code:     https://github.com/dyanikoglu/ALSV4_CPP
// Original Author: Doğa Can Yanıkoğlu
// Contributors:	Drakynfly

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "UtilityPlayerController.h"
#include "ALSPlayerController.generated.h"

class AALSBaseCharacter;

/**
 * Player controller class
 */
UCLASS(Blueprintable, BlueprintType)
class ALSV4_CPP_API AALSPlayerController : public AUtilityPlayerController
{
	GENERATED_BODY()

public:
	virtual void OnPossess(APawn* NewPawn) override;

	virtual void OnRep_Pawn() override;

	virtual void BeginPlayingState() override;

private:
	void SetupCamera();

	void SetupDebugInputs();
	
public:
	/** Main character reference */
	UPROPERTY(BlueprintReadOnly, Category = "ALS Player Controller")
	AALSBaseCharacter* PossessedCharacter = nullptr;

	/*
	If True:
		InputComponent->BindKey(EKeys::Tab, EInputEvent::IE_Pressed, DebugComp, &UALSDebugComponent::ToggleHud);
				InputComponent->BindKey(EKeys::V, EInputEvent::IE_Pressed, DebugComp, &UALSDebugComponent::ToggleDebugView);
				InputComponent->BindKey(EKeys::T, EInputEvent::IE_Pressed, DebugComp, &UALSDebugComponent::ToggleTraces);
				InputComponent->BindKey(EKeys::Y, EInputEvent::IE_Pressed, DebugComp, &UALSDebugComponent::ToggleDebugShapes);
				InputComponent->BindKey(EKeys::U, EInputEvent::IE_Pressed, DebugComp, &UALSDebugComponent::ToggleLayerColors);
				InputComponent->BindKey(EKeys::I, EInputEvent::IE_Pressed, DebugComp, &UALSDebugComponent::ToggleCharacterInfo);
				InputComponent->BindKey(EKeys::Z, EInputEvent::IE_Pressed, DebugComp, &UALSDebugComponent::ToggleSlomo);
				InputComponent->BindKey(EKeys::Comma, EInputEvent::IE_Pressed, DebugComp, &UALSDebugComponent::PreviousFocusedDebugCharacter);
				InputComponent->BindKey(EKeys::Period, EInputEvent::IE_Pressed, DebugComp, &UALSDebugComponent::NextFocusedDebugCharacter);
				InputComponent->BindKey(EKeys::M, EInputEvent::IE_Pressed, DebugComp, &UALSDebugComponent::ToggleDebugMesh);
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "ALS Player Controller")
	bool bEnableDebugBindings = true;
};
