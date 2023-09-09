#include "YB_InputView.h"
#include "YB_ViewItemBasis.h"
#include "YB_Window.h"


class YB_Window;


void YBConsoleViews::YB_InputView::OnKey(int* keycode)
{
	YB_ViewBasis::OnKey(keycode);
}

void YBConsoleViews::YB_InputView::OnChildReturn(YB_ViewMessageBasis* msgPtr, YB_ViewItemBasis* fromItemPtr)
{
	//Todo: check whether fromItemPtr is Submit type button; currently other item won't raise ChildReturn.
	if (msgPtr->Message == msgDef_Submit)
	{
		if (!this->ConfirmView.empty())
		{
			this->windowPtr->Goto(this->ConfirmView);
		}
		else
		{
			YB_ViewBasis::Submit();
		}
	}
	//YB_ViewBasis::OnChildReturn(msgPtr, fromItemPtr);
}

void YBConsoleViews::YB_InputView::OnConfirmReturn(YB_ViewMessageBasis* msgPtr, YB_ViewBasis* fromViewPtr)
{
	if (msgPtr->Message == msgDef_Yes) {
		YB_ViewBasis::Submit();
		this->windowPtr->Goto(this->GotoView);
	}
	if (msgPtr->Message == msgDef_No) {
		//Do nothing
	}
}

vector<char*> YBConsoleViews::YB_InputView::Render()
{
	return YB_ViewBasis::Render();
}
