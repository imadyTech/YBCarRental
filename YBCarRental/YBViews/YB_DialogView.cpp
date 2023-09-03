#include "YB_DialogView.h"

void YBConsoleViews::YB_DialogView::OnKey(int* keycode)
{
}

void YBConsoleViews::YB_DialogView::OnChildReturn(YB_ViewMessageBasis* Message)
{
}

vector<char*> YBConsoleViews::YB_DialogView::Render()
{
	return YB_ViewBasis::Render();
}
