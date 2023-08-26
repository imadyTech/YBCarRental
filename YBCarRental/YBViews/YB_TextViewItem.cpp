#include "YB_TextViewItem.h"


namespace YBConsoleViews
{

    vector<char*> YBConsoleViews::YB_TextViewItem::Render()
    {
        //return YB_ViewItemBasis::viewArray;
        return YB_ViewItemBasis::Render();
    }

    void YBConsoleViews::YB_TextViewItem::OnSelect()
    {
        //Do nothing for textViewItem.
    }

    void YBConsoleViews::YB_TextViewItem::OnReturn()
    {
        //Do nothing for textViewItem.
    }
}