#include "CHHero.h"
#include "Engine/Classes/Components/SkeletalMeshComponent.h"
#include "Engine/Classes/GameFramework/SpringArmComponent.h"
#include "Engine/Classes/Camera/CameraComponent.h"

ACHHero::ACHHero(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = ObjectInitializer.CreateDefaultSubobject<USceneComponent>(this, TEXT("Root"));

	Mesh = ObjectInitializer.CreateDefaultSubobject<USkeletalMeshComponent>(this, TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	SprintArm = ObjectInitializer.CreateDefaultSubobject<USpringArmComponent>(this, TEXT("SprintArm"));
	SprintArm->SetupAttachment(RootComponent);

	Camera = ObjectInitializer.CreateDefaultSubobject<UCameraComponent>(this, TEXT("Camera"));
	Camera->SetupAttachment(SprintArm);
}

void ACHHero::BeginPlay()
{
	Super::BeginPlay();
	
	Mesh->SetSimulatePhysics(true);
}

void ACHHero::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorLocation(Mesh->GetBodyInstance("neck_01")->GetUnrealWorldTransform().GetLocation());
}

void ACHHero::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

