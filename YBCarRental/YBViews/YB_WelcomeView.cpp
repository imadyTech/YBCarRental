#include "YB_WelcomeView.h"
#include "YB_Window.h"


class YB_Window;

void YBConsoleViews::YB_WelcomeView::OnKey(int* keycode)
{
	//if (this->ViewReturnCallback) {
	//	this->ViewReturnCallback();
	//}

	if (!this->GotoView.empty())
		windowPtr->Goto(this->GotoView);
}

void YBConsoleViews::YB_WelcomeView::OnChildReturn(YB_ViewMessageBasis* Message, YB_ViewItemBasis* fromItemPtr)
{
	YB_ViewBasis::OnChildReturn(Message, fromItemPtr);
}

vector<char*> YBConsoleViews::YB_WelcomeView::Render()
{
	return YB_ViewBasis::Render();
}
