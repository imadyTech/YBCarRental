#define _HAS_STD_BYTE 0

#include "YB_CarRental_LogicFactory.h"



bool YBCarRental::YB_CarRental_LogicFactory::RegisterDataSource(string* sourceName, YB_DataSource_Interface* service)
{
	try {
		YB_LogicFactory::serviceInstanceMap->insert(std::make_pair(*sourceName, service));
		return true;
	}
	catch (exception e)
	{
		return false;
	}
}

YB_DataSource_Interface* YBCarRental::YB_CarRental_LogicFactory::FindDataSource(string* sourceName)
{
	const auto& iterator = YB_LogicFactory::serviceInstanceMap->find(*sourceName);
	if (iterator != serviceInstanceMap->end())
		return iterator->second;
	else
		return nullptr;
}