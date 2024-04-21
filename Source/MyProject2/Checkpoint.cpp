// Checkpoint.cpp

#include "Checkpoint.h"

ACheckpoint::ACheckpoint()
{
    // Initialize components
    DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
    RootComponent = DefaultSceneRoot;

    CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
    CollisionComponent->SetupAttachment(RootComponent);

    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    MeshComponent->SetupAttachment(RootComponent);

    SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComponent"));
    SpriteComponent->SetupAttachment(RootComponent);

    Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
    Arrow->SetupAttachment(RootComponent);

    TextComponent = CreateDefaultSubobject<UTextRenderComponent>(TEXT("TextComponent"));
    TextComponent->SetupAttachment(RootComponent);

    AdditionalMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AdditionalMeshComponent"));
    AdditionalMeshComponent->SetupAttachment(RootComponent);

    // Dynamic material instance (if needed, configure further in BeginPlay or elsewhere)
    DynamicMaterialInstance = CreateDefaultSubobject<UMaterialInstanceDynamic>(TEXT("DynamicMaterialInstance"));
}

void ACheckpoint::BeginPlay()
{
    Super::BeginPlay();

    // Additional initialization or setup logic here
}

void ACheckpoint::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Update or gameplay logic here
}
