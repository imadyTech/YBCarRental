#include "YB_MenuView.h"
#include "YB_Window.h"


class YB_Window;

void YBConsoleViews::YB_MenuView::OnKey(int* keycode)
{
	YB_ViewBasis::OnKey(keycode);
}

void YBConsoleViews::YB_MenuView::OnChildReturn(YB_ViewMessageBasis* Message, YB_ViewItemBasis* fromItemPtr)
{
	try
	{
		windowPtr->Goto(Message->Message);
	}
	catch (exception e)
	{
		windowPtr->Goto("ErrorView");
	}
}

vector<char*> YBConsoleViews::YB_MenuView::Render()
{
	return YB_ViewBasis::Render();
}
