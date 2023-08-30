#include "YB_ViewFactory.h"

namespace YBConsoleViews
{
	void			YB_ViewFactory::LoadAllViews()
	{
		//It is not allowed to access repository before ReadAllLines().
		if (!(*this->repository).isReady)
			throw YB_RepositoryError();

		for (auto& pairValue : (*this->repository).allRecordLines)
		{
			YB_ViewBasis* viewPtr = this->CreateProduct(&(pairValue.second));
			//... Todo
			//viewPtr->DataSource = (*this->logicFactory).FindDataSource(&viewPtr->DataSourceName);

			try
			{
				//(*productPtr).Deserialize(pairValue.second);
				CreateSubViewitems(viewPtr, pairValue.second);
				viewPool.insert(std::make_pair(pairValue.first, viewPtr));
			}
			catch (exception e)
			{
				throw YB_FactoryError();
			}
		}
	}

	YB_ViewBasis*	YB_ViewFactory::GetView(int viewId) {
		auto iterator = viewPool.find(viewId);
		if (iterator != viewPool.end())
		{
			return iterator->second;
		}
		else
			return nullptr;
	}

	YB_ViewBasis*	YB_ViewFactory::GetView(string viewType) {
		for (auto& iterator : viewPool)
		{
			if (iterator.second->ViewType == viewType)
			{
				return iterator.second;
			}
		}
		return nullptr;
	};

	YB_ViewBasis*	YB_ViewFactory::CreateProduct(const string* serializeString)
	{
		YB_ViewBasis* basePtr = new YB_ViewBasis();
		basePtr->Deserialize(*serializeString);
		string type = basePtr->ViewType;

		if (type == "MenuView") {
			return new MenuView(*serializeString);
		}
		if (type == "WelcomeView") {
			return new WelcomeView(*serializeString);
		}
		if (type == "InputView") {
			return new InputView(*serializeString);
		}
		if (type == "DialogView") {
			return new DialogView(*serializeString);
		}
		if (type == "ListView") {
			return new ListView(*serializeString);
		}
		if (type == "DetailsView") {
			return new DetailsView(*serializeString);
		}
		return nullptr;
	}
		
	void			YB_ViewFactory::CreateSubViewitems(YB_ViewBasis* view, const string viewString)
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

	//std::unique_ptr<YB_ViewBasis>	YB_ViewFactory::CreateProduct(const string serializeString)
	//{
	//	YB_ViewBasis* basePtr = new YB_ViewBasis();
	//	basePtr->Deserialize(serializeString);
	//	string type = basePtr->ViewType;
	//	if (type == "MenuView") {
	//		return std::make_unique<MenuView>();
	//	}
	//	if (type == "WelcomeView") {
	//		return std::make_unique<WelcomeView>();
	//	}
	//	if (type == "InputView") {
	//		return std::make_unique<InputView>();
	//	}
	//	if (type == "DialogView") {
	//		return std::make_unique<DialogView>();
	//	}
	//	if (type == "ListView") {
	//		return std::make_unique<ListView>();
	//	}
	//	if (type == "DetailsView") {
	//		return std::make_unique<DetailsView>();
	//	}
	//	return nullptr;
	//}



}