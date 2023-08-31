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

        YB_ViewItemBasis::Render();

        if (isSelected) {
            const char* content = "->";
            size_t posY = h / 2;

            if (posY <= h)
            {
                size_t remainingLength = strlen(viewArray[posY]);
                memcpy(viewArray[posY], content, 2);
            }
        }
        return YB_ViewItemBasis::viewArray;

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