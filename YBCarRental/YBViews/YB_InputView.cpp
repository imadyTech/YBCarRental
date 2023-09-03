#include "YB_InputView.h"
#include "YB_ViewItemBasis.h"


void YBConsoleViews::YB_InputView::OnKey(int* keycode)
{
	YB_ViewBasis::OnKey(keycode);
}

void YBConsoleViews::YB_InputView::OnChildReturn(YB_ViewMessageBasis* msgPtr)
{
	YB_ViewBasis::OnChildReturn(msgPtr);
}

vector<char*> YBConsoleViews::YB_InputView::Render()
{
	return YB_ViewBasis::Render();
}
