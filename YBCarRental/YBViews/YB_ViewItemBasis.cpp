#include "YB_ViewItemBasis.h"

namespace YBConsoleViews {

	char* YBConsoleViews::YB_ViewItemBasis::Render()
	{
		return nullptr;
	}

	void YBConsoleViews::YB_ViewItemBasis::OnSelect()
	{
	}

	void YBConsoleViews::YB_ViewItemBasis::OnReturn()
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
			<< "x:" << x << persistentSeparator
			<< "y:" << y << persistentSeparator
			<< "w:" << w << persistentSeparator
			<< "h:" << h << persistentSeparator
			<< "isFocused:" << isFocused << persistentSeparator
			<< "isSelected:" << isSelected << persistentSeparator
			<< "isHidden:" << isHidden << persistentSeparator;
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
		isFocused = *YB_DataBasis::FindValue("h") == "1";
		isSelected = *YB_DataBasis::FindValue("h")=="1";
		isHidden = *YB_DataBasis::FindValue("h")=="1";
	}
}