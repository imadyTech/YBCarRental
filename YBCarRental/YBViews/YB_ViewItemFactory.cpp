#include "YB_ViewItemFactory.h"
#include "YB_ViewItemBasis.h"

namespace YBConsoleViews
{
	std::unique_ptr<YB_ViewItemBasis> YB_ViewItemFactory::CreateProduct(string serializeString)
	{
		YB_ViewItemBasis* basePtr = new YB_ViewItemBasis();
		basePtr->Deserialize(serializeString);

		string type = basePtr->ItemType;
		if (type == "TextItem")		return std::make_unique<TextItem>();
		if (type == "ButtonItem")	return std::make_unique<ButtonItem>();
		if (type == "InputItem")	return std::make_unique<InputItem>();
		if (type == "ListItem")		return std::make_unique<ListItem>();

		return nullptr;
	}
}