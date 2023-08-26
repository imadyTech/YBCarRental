#include "YB_ViewBasis.h"
#include "YB_ViewMessage.h"


namespace YBConsoleViews {
	YB_ViewBasis::YB_ViewBasis()
	{
	}
	YBConsoleViews::YB_ViewBasis::YB_ViewBasis(int* width, int* height)
	{
		this->w = *width;
		this->h = *height;
		viewContent = new vector<char*>(h);
	}

	void YBConsoleViews::YB_ViewBasis::AddViewItem(YB_ViewItemBasis item)
	{
		int currentSize = viewItems.size();
		viewItems.insert(std::make_pair(currentSize + 1, item));
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
			<< "Title:" << Title << ";"
			<< "w:" << w << ";"
			<< "h:" << h << ";";
	}

	void YB_ViewBasis::Deserialize(string line)
	{
		this->Deserialize(line, &persistentSeparator);
	}

	void YB_ViewBasis::Deserialize(string line, const char* separator)
	{
		YB_DataBasis::Deserialize(line, separator);

		Title[0] = const_cast<char*> ((*YB_DataBasis::FindValue("Title")).c_str());
		w = std::stoi(*YB_DataBasis::FindValue("w"));
		h = std::stoi(*YB_DataBasis::FindValue("h"));
	}


	vector<char*>* YBConsoleViews::YB_ViewBasis::Render()
	{
		for (const auto& item : viewItems)
		{

		}
		return viewContent;
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