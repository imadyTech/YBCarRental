#include "ButtonViewItem.h"

char* YBConsoleViews::ButtonViewItem::Render()
{
    return *viewContent;
}

void YBConsoleViews::ButtonViewItem::OnSelect()
{
    *isFocused = true;
}

void YBConsoleViews::ButtonViewItem::OnReturn()
{
    //Jump
}
