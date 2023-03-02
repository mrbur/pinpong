#include "PakPracticeGameInstance.h"

TArray<FMapInfo> UPakPracticeGameInstance::GetMapsInfo()
{
	return _DLCLoader->GetMapsInfo();
}
void UPakPracticeGameInstance::Init()
{
	_DLCLoader = NewObject<UDLCLoader>(this, "DLC_Loader");
}