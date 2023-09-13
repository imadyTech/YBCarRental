#ifndef YB_ViewItemFactory_H
#define YB_ViewItemFactory_H

#include "YB_ViewItemBasis.h"
#include "YB_ButtonItem.h"
#include "YB_InputItem.h"
#include "YB_ListItem.h"
#include "YB_ListHead.h"
#include "YB_TextItem.h"
#include "YB_MenuItem.h"
#include <YB_Errors.h>
#include "YB_Repository.h"

using namespace std;
using namespace YBPersistence;

namespace YBConsoleViews
{
	typedef YBConsoleViews::YB_ButtonItem		ButtonItem;
	typedef YBConsoleViews::YB_InputItem		InputItem;
	typedef YBConsoleViews::YB_ListItem			ListItem;
	typedef YBConsoleViews::YB_ListHead			ListHead;				//Table head
	typedef YBConsoleViews::YB_TextItem			TextItem;
	typedef YBConsoleViews::YB_MenuItem			MenuItem;


	class YB_ViewItemFactory
	{
	public:
		YB_ViewItemFactory() {};
		YB_ViewItemFactory(string viewItemRepoUrl) : YB_ViewItemFactory() {
			repository = new YB_Repository(viewItemRepoUrl);
			LoadAllItems();
		};

		/// <summary>
		/// Initialization (instantiate the repository);
		/// </summary>
		/// <param name="userRepo">The file path of User Repository.</param>
		void									LoadAllItems();
		/// <summary>
		/// YBView will pass the sub-items definition to create sub-viewItem, therefore not instantiated from a repo.
		/// </summary>
		/// <param name="itemDefinition"></param>
		YB_ViewItemBasis*						CreateViewItem(string itemDefinition);
		YB_ViewItemBasis*						GetViewItem(int viewId);
		YB_ViewItemBasis*						GetViewItem(string itemType);

	private:
		std::map<int, YB_ViewItemBasis*>		viewitemPool = {};
		YBPersistence::YB_Repository*			repository;

		/// <summary>
		/// create view in runtime upon to a Factory Design Pattern implementation
		/// </summary>
		std::unique_ptr<YB_ViewItemBasis>		CreateEmpty(string type);
		YB_ViewItemBasis*						CreateProduct(const string* serializeString);
		//std::unique_ptr<YB_ViewItemBasis>		CreateProduct(string itemDefinition);
	};
}

#endif // YB_ViewItemFactory_H