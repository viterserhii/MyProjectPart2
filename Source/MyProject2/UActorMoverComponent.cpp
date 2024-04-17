#include "UActorMoverComponent.h"
#include "Kismet/KismetMathLibrary.h"

UUActorMoverComponent::UUActorMoverComponent()
{
    PrimaryComponentTick.bCanEverTick = true;

    MovementDirection = FVector(300, 0, 0);
    DistanceToMove = 2050;
    bMovingForward = true;
}

void UUActorMoverComponent::BeginPlay()
{
    Super::BeginPlay();
    StartLocation = GetOwner()->GetActorLocation();
    TargetLocation = StartLocation + (MovementDirection.GetSafeNormal() * DistanceToMove);
    TotalDistanceMoved = 0.0f;
    bMovingForward = true;
}


void UUActorMoverComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (GetOwner())
    {
        float JourneyLength = DistanceToMove;
        TotalDistanceMoved += MovementDirection.Size() * DeltaTime;
        if (TotalDistanceMoved > JourneyLength) {
            TotalDistanceMoved = JourneyLength;
        }
        float Alpha = TotalDistanceMoved / JourneyLength;

        switch (EasingType)
        {
        case EEasingType::QuadraticIn:
            Alpha = FMath::InterpEaseIn(0.0f, 1.0f, Alpha, 2);
            break;
        case EEasingType::QuadraticOut:
            Alpha = FMath::InterpEaseOut(0.0f, 1.0f, Alpha, 2);
            break;
        case EEasingType::QuadraticInOut:
            Alpha = FMath::InterpEaseInOut(0.0f, 1.0f, Alpha, 2);
            break;
        default:
            Alpha = FMath::Lerp(0.0f, 1.0f, Alpha);
            break;
        }

        FVector NewLocation = FMath::Lerp(StartLocation, TargetLocation, Alpha);
        GetOwner()->SetActorLocation(NewLocation);

        if (Alpha >= 1.0)
        {
            bMovingForward = !bMovingForward;
            StartLocation = NewLocation;
            TargetLocation = StartLocation + (bMovingForward ? MovementDirection.GetSafeNormal() * DistanceToMove : -MovementDirection.GetSafeNormal() * DistanceToMove);
            TotalDistanceMoved = 0.0f;
        }
    }
}
