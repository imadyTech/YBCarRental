#include "YB_InputView.h"
#include "YB_ViewItemBasis.h"


void YBConsoleViews::YB_InputView::OnKey(int* keycode)
{
	YB_ViewBasis::OnKey(keycode);
}

void YBConsoleViews::YB_InputView::OnChildReturn(YB_ViewMessageBasis* msgPtr)
{
	if (msgPtr->Message == msgDef_Submit) {
		map<string, string> bindMap;
		//find out the viewItems which has 'Bind' tag.
		for (auto& iterator : this->subItemsList)
		{
			if (!iterator->Bind.empty())
				bindMap.insert(std::make_pair(iterator->Bind, iterator->Content));
		}
		if (!bindMap.empty())
			this->dataSource->onSubmit(&bindMap);
	}
	if (msgPtr->Message == msgDef_Yes) {}
	if (msgPtr->Message == msgDef_No) {}

}

vector<char*> YBConsoleViews::YB_InputView::Render()
{
	return YB_ViewBasis::Render();
}
