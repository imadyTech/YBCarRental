#include "YB_InputView.h"


void YBConsoleViews::YB_InputView::OnKey(int* keycode)
{
	YB_ViewBasis::OnKey(keycode);
}

void YBConsoleViews::YB_InputView::OnChildReturn(YB_ViewMessageBasis msg)
{
}

vector<char*> YBConsoleViews::YB_InputView::Render()
{
	return YB_ViewBasis::Render();
}
