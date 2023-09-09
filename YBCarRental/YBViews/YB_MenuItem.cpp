#include "YB_MenuItem.h"
#include "YB_ViewMessage.h"

namespace YBConsoleViews
{

	vector<char*> YBConsoleViews::YB_MenuItem::Render()
	{
		if (isHidden) {
			return YB_ViewItemBasis::viewArray;
		}

		YB_ViewItemBasis::Render();

		if (isFocused) {
			const char* content = ">>";
			size_t posY = h / 2;

			if (posY <= h)
			{
				size_t remainingLength = strlen(viewArray[posY]);
				memcpy(viewArray[posY], content, 2);
			}
		}
		return YB_ViewItemBasis::viewArray;

	}



	void YBConsoleViews::YB_MenuItem::OnReturn()
	{
		YB_MenuItemMessage Message= YB_MenuItemMessage(this->Link);
		this->parent->OnChildReturn(&Message, this);
	}
}