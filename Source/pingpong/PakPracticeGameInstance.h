#pragma once
#include "CoreMinimal.h"
#include "FDLCLoaderFileVisitor.h"
#include "Engine/GameInstance.h"
#include "PakPracticeGameInstance.generated.h"


UCLASS()
class PINGPONG_API UPakPracticeGameInstance : public UGameInstance
{
	GENERATED_BODY()
protected:
	UPROPERTY()
		UDLCLoader* _DLCLoader;
public:
	UFUNCTION(BlueprintCallable)
		TArray<FMapInfo> GetMapsInfo();
protected:
		void Init() override;
};