#include "YB_DetailsView.h"
#include "YB_Window.h"


class YB_Window;
using namespace YBConsoleViews;

void YBConsoleViews::YB_DetailsView::OnKey(int* keycode)
{
	windowPtr->Goto(this->fromViewPtr);
}
