#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EasingType.h" 
#include "UActorMoverComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MYPROJECT2_API UUActorMoverComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UUActorMoverComponent();

protected:
    virtual void BeginPlay() override;

public:
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
    FVector MovementDirection;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
    float DistanceToMove;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
    EEasingType EasingType; 

private:
    FVector StartLocation;
    FVector TargetLocation;
    float TotalDistanceMoved;
    bool bMovingForward;
};