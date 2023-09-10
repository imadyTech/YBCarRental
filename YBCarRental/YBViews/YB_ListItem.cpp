#include "YB_ListItem.h"

void YBConsoleViews::YB_ListItem::OnBind(string* contents)
{
    this->Content = *contents;
}

void YBConsoleViews::YB_ListItem::OnReturn()
{
    //windowPtr->Goto(xxxx)

}

std::vector<char*> YBConsoleViews::YB_ListItem::Render()
{
    return YB_ViewItemBasis::Render();
}
