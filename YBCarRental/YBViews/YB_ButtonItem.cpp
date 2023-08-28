#include "YB_ButtonItem.h"

namespace YBConsoleViews
{

    vector<char*> YBConsoleViews::YB_ButtonItem::Render()
    {
        return YB_ViewItemBasis::Render();
    }

    void YB_ButtonItem::OnKey(char* keycode)
    {
    }

    void YBConsoleViews::YB_ButtonItem::OnSelect()
    {
        isFocused = true;
    }

    void YBConsoleViews::YB_ButtonItem::OnReturn()
    {
        //Jump
    }
}