#include "MapInfoAsset.h"
FString FMapInfo::GetLevelName() 
{
	return _name.ToString();
}
FText FMapInfo::GetLevelDescription() 
{
	return _description;
}
FString FMapInfo::GetLevelReference()
{
	return _description.ToString();
}