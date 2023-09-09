#include "YB_ButtonItem.h"
#include "YB_ViewMessage.h"

namespace YBConsoleViews
{

	vector<char*> YBConsoleViews::YB_ButtonItem::Render()
	{
		if (isHidden) {
			return YB_ViewItemBasis::viewArray;
		}

		YB_ViewItemBasis::Render();

		if (isFocused) {
			const char* content = "->";
			size_t posY = h / 2;

			if (posY <= h)
			{
				size_t remainingLength = strlen(viewArray[posY]);
				memcpy(viewArray[posY], content, 2);
			}
		}
		return YB_ViewItemBasis::viewArray;

	}

	void YB_ButtonItem::OnKey(int* keycode)
	{
	}

	void YBConsoleViews::YB_ButtonItem::OnBackspace()
	{
		isFocused = true;
	}


	void YBConsoleViews::YB_ButtonItem::OnReturn()
	{
		if (this->ButtonType == "Submit") {
			YB_ButtonSubmitMessage Message;
			this->parent->OnChildReturn(&Message, this);
		}
		if (this->ButtonType == "Yes") {
			YB_ButtonYesMessage Message;
			this->parent->OnChildReturn(&Message, this);
		}
		if (this->ButtonType == "No") {
			YB_ButtonNoMessage Message;
			this->parent->OnChildReturn(&Message, this);
		}
	}
}