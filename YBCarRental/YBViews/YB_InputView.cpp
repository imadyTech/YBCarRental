#include "YB_InputView.h"
#include "YB_ViewItemBasis.h"
#include "YB_Window.h"


class YB_Window;


void YBConsoleViews::YB_InputView::OnKey(int* keycode)
{	YB_ViewBasis::OnKey(keycode);
}

void YBConsoleViews::YB_InputView::OnChildReturn(YB_ViewMessageBasis* msgPtr, YB_ViewItemBasis* fromItemPtr)
{
	YB_ViewBasis::OnChildReturn(msgPtr, fromItemPtr);
}

void YBConsoleViews::YB_InputView::OnConfirmReturn(YB_ViewMessageBasis* msgPtr, YB_ViewBasis* fromViewPtr)
{
	if (msgPtr->Message == Button_Type_Yes) {
		YB_ViewBasis::Submit();	
		if (!this->GotoView.empty()) {
			this->isKeepStatusFlag = false;
			this->windowPtr->Goto(this->GotoView);
		}
	}
	if (msgPtr->Message == Button_Type_No) {
		//Do nothing
	}
}

vector<char*> YBConsoleViews::YB_InputView::Render()
{
	return YB_ViewBasis::Render();
}
