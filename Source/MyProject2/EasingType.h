#include "CoreMinimal.h"
#include "EasingType.generated.h"

UENUM(BlueprintType)
enum class EEasingType : uint8
{
    Linear UMETA(DisplayName = "Linear"),
    QuadraticIn UMETA(DisplayName = "Quadratic In"),
    QuadraticOut UMETA(DisplayName = "Quadratic Out"),
    QuadraticInOut UMETA(DisplayName = "Quadratic In-Out")
    // Додайте інші типи за потреби
};