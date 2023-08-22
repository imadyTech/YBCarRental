#include "YB_ViewBasis.h"

YBConsoleViews::YB_ViewBasis::YB_ViewBasis(int* width, int* height)
{
	this->w = width;
	this->h = height;
}

vector<char*>* YBConsoleViews::YB_ViewBasis::Render()
{
	return nullptr;
}

void YBConsoleViews::YB_ViewBasis::OnSelect()
{
}

void YBConsoleViews::YB_ViewBasis::OnReturn()
{
}
