#include "YB_ViewBasis.h"
#include "YB_ViewMessage.h"


namespace YBConsoleViews {
	YB_ViewBasis::YB_ViewBasis()
	{
		YB_DataBasis::persistentSeparator = ';';
		FillBackground('*');
	}

	YBConsoleViews::YB_ViewBasis::YB_ViewBasis(int* width, int* height):YB_ViewBasis::YB_ViewBasis()
	{
		this->w = *width;
		this->h = *height;
	}

	void YBConsoleViews::YB_ViewBasis::AddViewItem(YB_ViewItemBasis item)
	{
		int currentSize = YB_ViewBasis::viewItems.size();
		YB_ViewBasis::viewItems.insert(std::make_pair(currentSize + 1, item));
	}

	string* YB_ViewBasis::Serialize()
	{
		std::stringstream ss;
		//Redirect to new function (instead of previous version overrided function)
		this->Serialize(ss);

		std::string* serializedString = new std::string(ss.str());
		return serializedString;
	}

	void YB_ViewBasis::Serialize(std::stringstream& strStream)
	{
		YB_DataBasis::Serialize(strStream);
		strStream
			<< "Title:" << Title << YB_DataBasis::persistentSeparator
			<< "ViewType:" << ViewType << YB_DataBasis::persistentSeparator
			<< "w:" << w << YB_DataBasis::persistentSeparator
			<< "h:" << h << YB_DataBasis::persistentSeparator;
	}

	void YB_ViewBasis::Deserialize(string line)
	{
		this->Deserialize(line, &persistentSeparator);
	}

	void YB_ViewBasis::Deserialize(string line, const char* separator)
	{
		YB_DataBasis::Deserialize(line, separator);
		Title = *YB_DataBasis::FindValue("Title");
		ViewType = *YB_DataBasis::FindValue("ViewType");
		w = std::stoi(*YB_DataBasis::FindValue("w"));
		h = std::stoi(*YB_DataBasis::FindValue("h"));
	}


	vector<char*>* YBConsoleViews::YB_ViewBasis::Render()
	{
		for (const auto& item : YB_ViewBasis::viewItems)
		{

		}
		return YB_ViewBasis::viewArray;
	}

	void YBConsoleViews::YB_ViewBasis::FillBackground(char background)
	{
		//fill the view background with a char
		for (int i = 0; i < YB_ViewBasis::h; ++i) {
			char* newLine = new char[YB_ViewBasis::w + 1];
			std::memset(newLine, '*', YB_ViewBasis::w);
			newLine[YB_ViewBasis::w] = '\0'; // Null-terminate the string
			(*YB_ViewBasis::viewArray).push_back(newLine);
		}
	}

	void YBConsoleViews::YB_ViewBasis::OnKeyInput(char* keycode)
	{
		//tab:	toggle active viewItem
		//enter: click active viewItem
		//num/char:	pass to active viewItem
		//Esc: quit (switch to exit confirm)
	}


	void YBConsoleViews::YB_ViewBasis::OnItemReturned(YB_ViewMessageBasis msg)
	{
	}
}