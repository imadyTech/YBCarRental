#include "YB_ViewItemFactory.h"
#include "YB_ViewItemBasis.h"

namespace YBConsoleViews
{
	void				YB_ViewItemFactory::LoadAllItems()
	{
		if (!(*repository).isReady)
			throw YB_RepositoryError();			//It is not allowed if never ReadAllLines().

		for (auto& pairValue : (*repository).allRecordLines)
		{
			//std::unique_ptr<YB_ViewItemBasis> viewPtr = this->CreateProduct(pairValue.second); //Pass the view serializeString
			YB_ViewItemBasis* view = this->CreateProduct(&pairValue.second); //Pass the view serializeString
			try
			{
				//(*view).Deserialize(pairValue.second);										//deserialize String
				viewitemPool.insert(std::make_pair(pairValue.first, view));
			}
			catch (exception e)
			{
				throw YB_FactoryError();
			}
		}
	}

	YB_ViewItemBasis*	YB_ViewItemFactory::CreateViewItem(string itemDefinition) {
		//std::unique_ptr<YB_ViewItemBasis> product = this->CreateProduct(itemDefinition);
		YB_ViewItemBasis* itemPtr = this->CreateProduct(&itemDefinition);
		if (itemPtr)
		{
			//(*item).Deserialize(itemDefinition);						//deserialize String

			auto it = viewitemPool.find(itemPtr->Id);
			if (it != viewitemPool.end())								//Already existed; Update.
			{
				it->second = itemPtr;									//replace the viewitem in the pool
			}
			else
			{
				try
				{
					viewitemPool.insert(std::make_pair(itemPtr->Id, itemPtr));
				}
				catch (exception e)
				{
					throw YB_FactoryError();
				}
			}
		}
		return itemPtr;							//Caution: itemPtr's member properties will be emptied after return.
		//return this->GetViewItem((itemPtr)->Id);	//This works.
	}

	YB_ViewItemBasis*	YB_ViewItemFactory::GetViewItem(int viewId) {
		auto iterator = viewitemPool.find(viewId);
		if (iterator != viewitemPool.end())
		{
			return iterator->second;
		}
		else
			return nullptr;
	}

	YB_ViewItemBasis*	YB_ViewItemFactory::GetViewItem(string itemType) {
		for (auto& iterator : viewitemPool)
		{
			if (iterator.second->ItemType == itemType)
			{
				return iterator.second;
			}
		}
		return nullptr;
	};

	//std::unique_ptr<YB_ViewItemBasis> YB_ViewItemFactory::CreateProduct(const string serializeString)
	//{
	//	YB_ViewItemBasis* basePtr = new YB_ViewItemBasis();
	//	basePtr->Deserialize(serializeString);

	//	if (type == "TextItem") { return std::make_unique<TextItem>(serializeString); }
	//	if (type == "ButtonItem") { return std::make_unique<ButtonItem>(serializeString); }
	//	if (type == "InputItem") { return std::make_unique<InputItem>(serializeString); }
	//	if (type == "ListItem") { return std::make_unique<ListItem>(serializeString); }
	//	return nullptr;
	//}
	YB_ViewItemBasis*	YB_ViewItemFactory::CreateProduct(const string* serializeString)
	{
		YB_ViewItemBasis basePtr = YB_ViewItemBasis();
		basePtr.Deserialize(*serializeString);

		string type = basePtr.ItemType;

		if (type == "TextItem")		{ return new TextItem(*serializeString); }
		if (type == "ButtonItem")	{ return new ButtonItem(*serializeString); }
		if (type == "InputItem")	{ return new InputItem(*serializeString); }
		if (type == "ListItem")		{ return new ListItem(*serializeString); }
		return &basePtr;
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