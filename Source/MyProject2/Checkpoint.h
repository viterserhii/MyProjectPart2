#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/TextRenderComponent.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundCue.h"
#include "PaperSpriteComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Checkpoint.generated.h"

UCLASS()
class MYPROJECT2_API ACheckpoint : public AActor
{
    GENERATED_BODY()

public:
    ACheckpoint();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;
    virtual void OnConstruction(const FTransform& Transform) override;
    UFUNCTION()
    void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    USphereComponent* CollisionComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* MeshComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UMaterialInterface* BaseMaterial;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UPaperSpriteComponent* SpriteComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UArrowComponent* Arrow;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UTextRenderComponent* TextComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* AdditionalMeshComponent;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Components")
    UMaterialInstanceDynamic* DynamicMaterialInstance;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    USceneComponent* DefaultSceneRoot;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UAudioComponent* AudioComponent; 

    UPROPERTY(EditAnywhere, Category = "Sound")
    USoundCue* SoundToPlay;

};
