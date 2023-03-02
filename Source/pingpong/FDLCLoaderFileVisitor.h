#pragma once
#include "CoreMinimal.h"
#include "MapInfoAsset.h"
#include "UObject/NoExportTypes.h"
#include "Runtime/PakFile/Public/IPlatformFilePak.h"
#include "FDLCLoaderFileVisitor.generated.h"


class PINGPONG_API FDLCLoaderFileVisitor : public
	IPlatformFile::FDirectoryVisitor
{
public:
	virtual bool Visit(const TCHAR* FilenameOrDirectory, bool bIsDirectory)
		override
	{
		if (!bIsDirectory)
		{
			Files.Add(FilenameOrDirectory);
		}
		return true;
	}
	TArray<FString> Files;
};

UCLASS()
class PINGPONG_API UDLCLoader : public UObject
{
	GENERATED_BODY()

public:
	bool ReadDLCMapsInfo();
	TArray<FMapInfo> GetMapsInfo();
	void Clear();
private:
	TArray<FString> GetClassesToLoad();
	UPROPERTY()
		TArray<FMapInfo> _mapsInfo;
	TArray<FString> LoadDLC();
	// DLC methods
	bool MountDLC(const FString& PakFilename);
	bool UnmountDLC(const FString& PakFilename);
	int32 GetDLCOrder(const FString& PakFilePath);
	void RegisterMountPoint(const FString& RootPath, const FString&
		ContentPath);
	TArray<FString> GetFilesInDLC(const FString& Directory);
	bool ReadPakFile(FString PakFileName);
	UClass* LoadClassFromDLC(const FString& Filename);

	FPakPlatformFile* GetDLCFile();
	FPakPlatformFile* DLCFile = nullptr;
#if UE_BUILD_SHIPPING == 0
	IPlatformFile* OriginalPlatformFile = nullptr;
#endif

};
