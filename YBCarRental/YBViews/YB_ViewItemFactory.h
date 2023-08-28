#ifndef YB_ViewItemFactory_H
#define YB_ViewItemFactory_H

#include "YB_ViewItemBasis.h"
#include "YB_ButtonItem.h"
#include "YB_InputItem.h"
#include "YB_ListItem.h"
#include "YB_TextItem.h"

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

		/// <summary>
		/// Initialization (instantiate the repository);
		/// </summary>
		/// <param name="userRepo">The file path of User Repository.</param>
		//YB_ViewItemFactory(string viewItemRepoUrl) {
		//	repository = YB_Repository(viewItemRepoUrl);
		//};

		YB_ViewItemBasis* GetView(int viewId) {
			auto iterator = viewitemPool.find(viewId);
			if (iterator != viewitemPool.end())
			{
				return iterator->second;
			}
			else
				return nullptr;
		}

		YB_ViewItemBasis* GetView(string itemType) {
			for (auto& iterator : viewitemPool)
			{
				if ((*(iterator.second)).ItemType == itemType)
				{
					return iterator.second;
				}
			}
			return nullptr;
		};



	private:
		std::map<int, YB_ViewItemBasis*>		viewitemPool;

		/// <summary>
		/// create view in runtime upon to a Factory Design Pattern implementation
		/// </summary>
		std::unique_ptr<YB_ViewItemBasis>		CreateProduct(string serializeString);
	};

}

#endif // YB_ViewItemFactory_H