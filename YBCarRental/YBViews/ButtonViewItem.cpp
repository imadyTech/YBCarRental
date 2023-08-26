#include "ButtonViewItem.h"

namespace YBConsoleViews
{

    vector<char*> YBConsoleViews::ButtonViewItem::Render()
    {
        return YB_ViewItemBasis::Render();
    }

    void YBConsoleViews::ButtonViewItem::OnSelect()
    {
        isFocused = true;
    }

    void YBConsoleViews::ButtonViewItem::OnReturn()
    {
        //Jump
    }
}