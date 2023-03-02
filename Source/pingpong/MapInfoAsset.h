#pragma once
#include "CoreMinimal.h"
#include "Engine/PrimaryAssetLabel.h"
#include "UObject/NoExportTypes.h"
#include "MapInfoAsset.generated.h"

USTRUCT(BlueprintType, Blueprintable)
struct FMapInfo
{
	GENERATED_BODY()


	FString GetLevelName();

	FText GetLevelDescription(); 
	
	FString GetLevelReference();

	UPROPERTY(VisibleAnywhere)
		FText _name;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FText _description;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FSoftObjectPath _primaryAsset;
	UPROPERTY()
		UPrimaryAssetLabel* _primaryAssetLable;
};


UCLASS()
class PINGPONG_API UMapInfoBlueprintFunctionLibrary : public
	UBlueprintFunctionLibrary
{
	GENERATED_BODY()
		/*Blueprint Function to return the value from the struct*/
		UFUNCTION(BlueprintCallable, BlueprintPure, Category =
			"MapInfo|Methods")
		static FString GetLevelReference(UPARAM(ref) FMapInfo& MyStructRef) {
			return MyStructRef.GetLevelReference();
	};
};


UCLASS(BlueprintType, Blueprintable)
class PINGPONG_API UMapInfoAsset : public UObject
{
	GENERATED_BODY()
public:
	UMapInfoAsset(const FObjectInitializer& ObjectInitializer)
		: Super(ObjectInitializer)
	{
	}
	UPROPERTY(EditAnywhere)
		FMapInfo _mapInfo;
};