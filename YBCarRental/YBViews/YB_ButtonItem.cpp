#include "YB_ButtonItem.h"

namespace YBConsoleViews
{

    vector<char*> YBConsoleViews::YB_ButtonItem::Render()
    {
        if (!isHidden) {
            if (isFocused)
                this->Fill_Background(this->Background);
            else
                Clear_Background();
        }

        return YB_ViewItemBasis::Render();
    }

    void YB_ButtonItem::OnKey(int* keycode)
    {
    }

    void YBConsoleViews::YB_ButtonItem::OnBackspace()
    {
        isFocused = true;
    }


    void YBConsoleViews::YB_ButtonItem::OnReturn()
    {
        //Jump
    }
}