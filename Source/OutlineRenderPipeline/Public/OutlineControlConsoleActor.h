// Copyright 2024 kafues511. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OutlineSettings.h"
#include "OutlineControlConsoleActor.generated.h"

UCLASS()
class OUTLINERENDERPIPELINE_API AOutlineControlConsoleActor : public AActor
{
	GENERATED_BODY()
	
public:
	AOutlineControlConsoleActor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

public:
	//~ Begin AActor interface
#if WITH_EDITOR
	virtual void RerunConstructionScripts() override;
	virtual void OnConstruction(const FTransform& Transform) override;
#endif
	//~ End AAcotr interface

public:
	/**  */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Outline Settings")
	FOutlineSettings OutlineSettings;

};
