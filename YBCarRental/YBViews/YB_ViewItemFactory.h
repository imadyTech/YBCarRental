#ifndef YB_ViewItemFactory_H
#define YB_ViewItemFactory_H

#include "YB_ViewItemBasis.h"
#include "YB_ButtonItem.h"
#include "YB_InputItem.h"
#include "YB_ListItem.h"
#include "YB_TextItem.h"
#include <YB_Errors.h>
#include "YB_Repository.h"

using namespace std;
using namespace YBPersistence;

namespace YBConsoleViews
{
	typedef YBConsoleViews::YB_ButtonItem		ButtonItem;
	typedef YBConsoleViews::YB_InputItem		InputItem;
	typedef YBConsoleViews::YB_ListItem			ListItem;
	typedef YBConsoleViews::YB_TextItem			TextItem;


	class YB_ViewItemFactory
	{
	public:
		YB_ViewItemFactory() {};
		YB_ViewItemFactory(string viewItemRepoUrl) : YB_ViewItemFactory() {
			repository = YB_Repository(viewItemRepoUrl);
			LoadAllItems();
		};


		/// <summary>
		/// Initialization (instantiate the repository);
		/// </summary>
		/// <param name="userRepo">The file path of User Repository.</param>
		//YB_ViewItemFactory(string viewItemRepoUrl) {
		//	repository = YB_Repository(viewItemRepoUrl);
		//};
		void LoadAllItems()
		{
			if (!this->repository.isReady)
				throw YB_RepositoryError();			//It is not allowed if never ReadAllLines().

			for (auto& pairValue : repository.allRecordLines)
			{
				std::unique_ptr<YB_ViewItemBasis> viewPtr = this->CreateProduct(pairValue.second); //Pass the view serializeString
				YB_ViewItemBasis* view = viewPtr.get();
				try
				{
					//(*view).Deserialize(pairValue.second);										//deserialize String
					viewitemPool.insert(std::make_pair(pairValue.first, *view));
				}
				catch (exception e)
				{
					throw YB_FactoryError();
				}
			}
		}

		void CreateViewItem(string itemDefinition) {
			std::unique_ptr<YB_ViewItemBasis> itemPtr = this->CreateProduct(itemDefinition);
			YB_ViewItemBasis* item = itemPtr.get();
			if (item)
			{
				//(*item).Deserialize(itemDefinition);										//deserialize String

				auto it = viewitemPool.find(item->Id);
				if (it != viewitemPool.end())
				{
					it->second = *item;		//replace the viewitem in the pool
				}
				else
				{
					try
					{
						viewitemPool.insert(std::make_pair(item->Id, *item));
					}
					catch (exception e)
					{
						throw YB_FactoryError();
					}
				}
			}
		}

		YB_ViewItemBasis* GetViewItem(int viewId) {
			auto iterator = viewitemPool.find(viewId);
			if (iterator != viewitemPool.end())
			{
				return &iterator->second;
			}
			else
				return nullptr;
		}

		YB_ViewItemBasis* GetViewItem(string itemType) {
			for (auto& iterator : viewitemPool)
			{
				if (iterator.second.ItemType == itemType)
				{
					return &iterator.second;
				}
			}
			return nullptr;
		};



	private:
		std::map<int, YB_ViewItemBasis>			viewitemPool;
		YBPersistence::YB_Repository			repository;

		/// <summary>
		/// create view in runtime upon to a Factory Design Pattern implementation
		/// </summary>
		std::unique_ptr<YB_ViewItemBasis>		CreateEmpty(string type);
		std::unique_ptr<YB_ViewItemBasis>		CreateProduct(string itemDefinition);
	};

}

#endif // YB_ViewItemFactory_H