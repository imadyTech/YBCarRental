#include "YB_WelcomeView.h"
#include "YB_Window.h"


class YB_Window;

void YBConsoleViews::YB_WelcomeView::OnKey(int* keycode)
{
	//if (this->ViewReturnCallback) {
	//	this->ViewReturnCallback();
	//}
	if (this->dataSource)
		YB_ViewBasis::Submit();
	if (!this->GotoView.empty())
		windowPtr->Goto(this->GotoView);
}

