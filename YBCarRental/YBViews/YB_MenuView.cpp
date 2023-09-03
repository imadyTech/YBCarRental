#include "YB_MenuView.h"

void YBConsoleViews::YB_MenuView::OnKey(int* keycode)
{
	YB_ViewBasis::OnKey(keycode);
}

void YBConsoleViews::YB_MenuView::OnChildReturn(YB_ViewMessageBasis* msg)
{
}

vector<char*> YBConsoleViews::YB_MenuView::Render()
{
	return YB_ViewBasis::Render();
}
