#include "UActorMoverComponent.h"
#include "Kismet/KismetMathLibrary.h"

UActorMoverComponent::UActorMoverComponent()
{
    PrimaryComponentTick.bCanEverTick = true;

    TargetPointB = FVector(0.f, 0.f, 0.f);
    Speed = 200.f; 
    PauseDuration = 0.0f; 
    EasingType = EEasingType::Linear; 
    bIsMoving = false;
    CurrentPauseTime = 0.0f;
    bMovingToB = true; 
    CurrentTime = 0.0f;
}

void UActorMoverComponent::BeginPlay()
{
    Super::BeginPlay();

    StartPointA = GetOwner()->GetActorLocation(); 
    CurrentTargetPoint = TargetPointB;          
    CurrentPauseTime = PauseDuration;           
    bIsMoving = false;                        
}

void UActorMoverComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (!bIsMoving)
    {
        CurrentPauseTime -= DeltaTime;
        if (CurrentPauseTime <= 0.0f)
        {
            bIsMoving = true;
            CurrentTime = 0.0f; 
        }
        return;
    }

    FVector StartLocation = bMovingToB ? StartPointA : TargetPointB;
    FVector EndLocation = bMovingToB ? TargetPointB : StartPointA;

    float JourneyLength = FVector::Distance(StartLocation, EndLocation);
    CurrentTime += DeltaTime * Speed / JourneyLength;

    float Alpha = FMath::Clamp(CurrentTime, 0.0f, 1.0f);

    switch (EasingType)
    {
    case EEasingType::QuadraticInOut:
        Alpha = FMath::InterpEaseInOut(0.0f, 1.0f, Alpha, 2.0f);
        break;
    default:
        break;
    }

    FVector NewLocation = FMath::Lerp(StartLocation, EndLocation, Alpha);
    GetOwner()->SetActorLocation(NewLocation);

    if (Alpha >= 1.0f)
    {
        bIsMoving = false;
        CurrentPauseTime = PauseDuration;

        bMovingToB = !bMovingToB;
        CurrentTime = 0.0f;
    }
}
