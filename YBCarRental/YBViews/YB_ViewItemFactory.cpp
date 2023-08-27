#include "YB_ViewItemFactory.h"

namespace YBConsoleViews
{

	std::unique_ptr<YB_ViewItemBasis> YB_ViewItemFactory::CreateProduct(string viewType)
	{
		if (viewType == "TitleItem") return std::make_unique<YB_ViewItemBasis>();
		if (viewType == "TextItem") return std::make_unique<YB_ViewItemBasis>();
		if (viewType == "ButtonItem") return std::make_unique<YB_ViewItemBasis>();
		if (viewType == "InputItem") return std::make_unique<YB_ViewItemBasis>();
		if (viewType == "ListItem") return std::make_unique<YB_ViewItemBasis>();
		return nullptr;
	}
}