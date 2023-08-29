#include "YB_TextItem.h"


namespace YBConsoleViews
{

	vector<char*> YBConsoleViews::YB_TextItem::Render()
	{
		if (!isHidden) {
			//isFocused property doesn't affect textItem.
			//always fill the item background.
			this->Fill_Background(this->Background);
			return YB_ViewItemBasis::Render();
		}
		return {};
	}

	void YB_TextItem::OnKey(int* keycode)
	{
	}

	void YBConsoleViews::YB_TextItem::OnBackspace()
	{
		//Do nothing for textViewItem.
	}

	void YBConsoleViews::YB_TextItem::OnReturn()
	{
		//Do nothing for textViewItem.
	}
}