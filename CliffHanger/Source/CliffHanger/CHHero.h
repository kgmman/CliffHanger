#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CHHero.generated.h"

class USkeletalMeshComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class CLIFFHANGER_API ACHHero : public APawn
{
	GENERATED_UCLASS_BODY()
public:
	// Sets default values for this pawn's properties
	ACHHero();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Hero)
	USkeletalMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Hero)
	USpringArmComponent* SprintArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Hero)
	UCameraComponent* Camera;
};
