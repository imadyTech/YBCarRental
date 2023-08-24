#include "YB_TextViewItem.h"

char* YBConsoleViews::YB_TextViewItem::Render()
{
    return *viewContent;
}

void YBConsoleViews::YB_TextViewItem::OnSelect()
{
    //Do nothing for textViewItem.
}

void YBConsoleViews::YB_TextViewItem::OnReturn()
{
    //Do nothing for textViewItem.
}
