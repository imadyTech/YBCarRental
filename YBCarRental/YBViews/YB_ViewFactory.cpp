#include "YB_ViewFactory.h"

namespace YBConsoleViews
{
	void							YB_ViewFactory::LoadAllViews()
	{
		//It is not allowed to access repository before ReadAllLines().
		if (!this->repository.isReady)
			throw YB_RepositoryError();

		for (auto& pairValue : repository.allRecordLines)
		{
			std::unique_ptr<YB_ViewBasis> product = this->CreateProduct(pairValue.second);
			YB_ViewBasis* viewPtr = product.get();
			try
			{
				(*viewPtr).Deserialize(pairValue.second);
				CreateViewitem(viewPtr, pairValue.second);
				viewPool.insert(std::make_pair(pairValue.first, *viewPtr));
			}
			catch (exception e)
			{
				throw YB_FactoryError();
			}
		}
	}

	YB_ViewBasis* YB_ViewFactory::GetView(int viewId) {
		auto iterator = viewPool.find(viewId);
		if (iterator != viewPool.end())
		{
			return &(iterator->second);
		}
		else
			return nullptr;
	}

	YB_ViewBasis* YB_ViewFactory::GetView(string viewType) {
		for (auto& iterator : viewPool)
		{
			if ((iterator.second).ViewType == viewType)
			{
				return &iterator.second;
			}
		}
		return nullptr;
	};

	std::unique_ptr<YB_ViewBasis>	YB_ViewFactory::CreateProduct(const string serializeString)
	{
		YB_ViewBasis* basePtr = new YB_ViewBasis();
		basePtr->Deserialize(serializeString);

		string type = basePtr->ViewType;
		if (type == "MenuView") {
			return std::make_unique<MenuView>();
		}
		if (type == "WelcomeView") {
			return std::make_unique<WelcomeView>();
		}
		if (type == "InputView") {
			return std::make_unique<InputView>();
		}
		if (type == "DialogView") {
			return std::make_unique<DialogView>();
		}
		if (type == "ListView") {
			return std::make_unique<ListView>();
		}
		if (type == "DetailsView") {
			return std::make_unique<DetailsView>();
		}
		return nullptr;
	}

	void							YB_ViewFactory::CreateViewitem(YB_ViewBasis* view, const string viewString)
	{
		auto itemsDef = (*view).FindValues("item");
		if (!itemsDef.empty())
		{
			for (auto& itemIdPiar : itemsDef) {
				string itemSubString = itemIdPiar.second;
				YB_ViewItemBasis* child = this->viewItemFactory.CreateViewItem(itemSubString);
				view->subItemsList.push_back(child);
			}
		}
	}
}