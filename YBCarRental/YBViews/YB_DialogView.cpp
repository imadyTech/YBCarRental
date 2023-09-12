#include "YB_DialogView.h"
#include "YB_Window.h"

class YB_Window;

void YBConsoleViews::YB_DialogView::OnKey(int* keycode)
{
	if (*keycode == 9 || *keycode == 13)											//only Tab/Return will be processed for DialogView
		YB_ViewBasis::OnKey(keycode);
}

void YBConsoleViews::YB_DialogView::OnChildReturn(YB_ViewMessageBasis* msgPtr, YB_ViewItemBasis* fromItemPtr)
{
	//Todo: untested
	//When "yes" or "no" is clicked, viewItem pass in a message, will be forwarded
	this->fromViewPtr->OnConfirmReturn(msgPtr, this);
	//this->windowPtr->Goto(this->fromViewPtr);
}

vector<char*> YBConsoleViews::YB_DialogView::Render()
{
	return YB_ViewBasis::Render();
}
