#include "YB_TextItem.h"


namespace YBConsoleViews
{

    vector<char*> YBConsoleViews::YB_TextItem::Render()
    {
        //return YB_ViewItemBasis::viewArray;
        return YB_ViewItemBasis::Render();
    }

    void YB_TextItem::OnKey(int* keycode)
    {
    }

    void YBConsoleViews::YB_TextItem::OnBackspace()
    {
        //Do nothing for textViewItem.
    }

    void YBConsoleViews::YB_TextItem::OnReturn()
    {
        //Do nothing for textViewItem.
    }
}