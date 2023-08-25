#include "YB_DataBasis.h"
#include <stdio.h>



namespace YBPersistence
{

	YB_DataBasis::YB_DataBasis()
	{
	}

	std::string* YB_DataBasis::Serialize()
	{
		return nullptr;
	}

	//void YB_DataBasis::Serialize(ofstream* output)
	//{
	//}

	void YB_DataBasis::Deserialize(std::string line, const char* separator)
	{
		YB_DataBasis::SplitLine(&line, separator);			//fill the map
		Id = std::stoi(*YB_DataBasis::FindValue("Id"));
	}


}