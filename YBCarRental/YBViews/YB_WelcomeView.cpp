#include "YB_WelcomeView.h"

void YBConsoleViews::YB_WelcomeView::OnKey(int* keycode)
{
	if (this->ViewReturnCallback) {
		this->ViewReturnCallback();
	}
}

void YBConsoleViews::YB_WelcomeView::OnChildReturn(YB_ViewMessageBasis* Message)
{
}

vector<char*> YBConsoleViews::YB_WelcomeView::Render()
{
	return YB_ViewBasis::Render();
}
