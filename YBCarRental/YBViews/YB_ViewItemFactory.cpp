#include "YB_ViewItemFactory.h"
#include "YB_ViewItemBasis.h"

namespace YBConsoleViews
{
	std::unique_ptr<YB_ViewItemBasis> YB_ViewItemFactory::CreateProduct(const string serializeString)
	{


		YB_ViewItemBasis* basePtr = new YB_ViewItemBasis();
		basePtr->Deserialize(serializeString);

		//*basePtr->SplitLine(&serializeString, &basePtr->persistentSeparator);
		//string type = *basePtr->FindValue("ItemType");
		string type = basePtr->ItemType;

		if (type == "TextItem") { return std::make_unique<TextItem>(serializeString); }
		if (type == "ButtonItem") { return std::make_unique<ButtonItem>(serializeString); }
		if (type == "InputItem") { return std::make_unique<InputItem>(serializeString); }
		if (type == "ListItem") { return std::make_unique<ListItem>(serializeString); }
		//if (type == "TextItem")		return std::make_unique<TextItem>(basePtr->w, basePtr->h);
		//if (type == "ButtonItem")	return std::make_unique<ButtonItem>(basePtr->w, basePtr->h);
		//if (type == "InputItem")	return std::make_unique<InputItem>(basePtr->w, basePtr->h);
		//if (type == "ListItem")		return std::make_unique<ListItem>(basePtr->w, basePtr->h);

		return nullptr;
	}
	std::unique_ptr<YB_ViewItemBasis> YB_ViewItemFactory::CreateEmpty(string type)
	{
		if (type == "TextItem")		return std::make_unique<TextItem>();
		if (type == "ButtonItem")	return std::make_unique<ButtonItem>();
		if (type == "InputItem")	return std::make_unique<InputItem>();
		if (type == "ListItem")		return std::make_unique<ListItem>();
		return nullptr;
	}


}