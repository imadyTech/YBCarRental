#include "YB_ViewItemBasis.h"
#include <vector>

using namespace YBConsoleViews;

vector<char*> YB_ViewItemBasis::Render()
{
	return YB_ViewItemBasis::viewArray;
}

void YB_ViewItemBasis::OnSelect()
{
}

void YB_ViewItemBasis::OnReturn()
{
}


string* YB_ViewItemBasis::Serialize()
{
	std::stringstream ss;
	//Redirect to new function (instead of previous version overrided function)
	this->Serialize(ss);

	std::string* serializedString = new std::string(ss.str());
	return serializedString;
}

void YB_ViewItemBasis::Serialize(std::stringstream& strStream)
{
	YB_DataBasis::Serialize(strStream);
	strStream
		<< "x:" << x << YB_DataBasis::persistentSeparator
		<< "y:" << y << YB_DataBasis::persistentSeparator
		<< "w:" << w << YB_DataBasis::persistentSeparator
		<< "h:" << h << YB_DataBasis::persistentSeparator
		<< "isFocused:" << isFocused << YB_DataBasis::persistentSeparator
		<< "isSelected:" << isSelected << YB_DataBasis::persistentSeparator
		<< "isHidden:" << isHidden << YB_DataBasis::persistentSeparator;
}

void YB_ViewItemBasis::Deserialize(string line)
{
	this->Deserialize(line, &persistentSeparator);
}


void YB_ViewItemBasis::Deserialize(string line, const char* separator)
{
	YB_DataBasis::Deserialize(line, separator);

	x = std::stoi(*YB_DataBasis::FindValue("x"));
	y = std::stoi(*YB_DataBasis::FindValue("y"));
	w = std::stoi(*YB_DataBasis::FindValue("w"));
	h = std::stoi(*YB_DataBasis::FindValue("h"));
	isFocused = *YB_DataBasis::FindValue("isFocused") == "1";
	isSelected = *YB_DataBasis::FindValue("isSelected") == "1";
	isHidden = *YB_DataBasis::FindValue("isHidden") == "1";
}
