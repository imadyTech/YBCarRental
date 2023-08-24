#include "YB_ViewBasis.h"
#include "YB_ViewMessage.h"


namespace YBConsoleViews {
	YB_ViewBasis::YB_ViewBasis()
	{
	}
	YBConsoleViews::YB_ViewBasis::YB_ViewBasis(int* width, int* height)
	{
		this->w = width;
		this->h = height;
		viewContent = new vector<char*>(*h);
	}

	void YBConsoleViews::YB_ViewBasis::AddViewItem(YB_ViewItemBasis item)
	{
		int currentSize = viewItems.size();
		viewItems.insert(std::make_pair(currentSize + 1, item));
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