#include "YB_ListView.h"
#include "YB_Window.h"


class YB_Window;

void YBConsoleViews::YB_ListView::Init()
{
}

void YBConsoleViews::YB_ListView::OnKey(int* keycode)
{
}

void YBConsoleViews::YB_ListView::OnChildReturn(YB_ViewMessageBasis* msgPtr, YB_ViewItemBasis* fromItemPtr)
{
}

void YBConsoleViews::YB_ListView::OnConfirmReturn(YB_ViewMessageBasis* msgPtr, YB_ViewBasis* fromViewPtr)
{
}

vector<char*> YBConsoleViews::YB_ListView::Render()
{
	return YB_ViewBasis::Render();
}
