#include "YB_DataBasis.h"
#include <stdio.h>



namespace YBPersistence
{

	YB_DataBasis::YB_DataBasis()
	{
		stringPairsMap = map<std::string, std::string>();
	}

	[[deprecated("Deprecated, use Serialize(std::stringstream& strStream) instead.")]]
	std::string* YB_DataBasis::Serialize()
	{
		std::stringstream strStream;
		strStream <<"Id:" << Id << this->persistentSeparator;

		std::string* serializedString = new std::string(strStream.str());
		return serializedString;
	}

	void YB_DataBasis::Serialize(std::stringstream& strStream)
	{
		strStream <<"Id:" << Id << this->persistentSeparator;
	}

	//Obsoleted
	//void YB_DataBasis::Serialize(ofstream* output)
	//{
	//}

	void YB_DataBasis::Deserialize(std::string line, const char* separator)
	{
		YB_DataBasis::SplitLine(&line, separator);			//to string:string pairs in stringPairsMap
		if(YB_DataBasis::FindValue("Id")) Id = std::stoi(*YB_DataBasis::FindValue("Id"));
	}


}