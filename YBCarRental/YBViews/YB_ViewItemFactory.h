#ifndef YB_ViewItemFactory_H
#define YB_ViewItemFactory_H

#include "YB_ViewItemBasis.h"
#include "YB_Repository.h"

using namespace std;
using namespace YBPersistence;

namespace YBConsoleViews
{
	class YB_ViewItemFactory
	{
	public:
		/// <summary>
		/// Constructor and initialization;
		/// </summary>
		/// <param name="userRepo">The file path of User Repository.</param>
		YB_ViewItemFactory(string viewRepoUrl) {
			repository = YB_Repository(viewRepoUrl);
		};

		/// <summary>
		/// objectize all text def in repo to YB_ViewItem objects
		/// </summary>
		void LoadAllViewItems() {
		};

		/// <summary>
		/// Find the view through search the Title of view (make sure view.Title has no overlap. No conflict check mechanism in this project.)
		/// </summary>
		/// <param name="viewTitle"></param>
		/// <returns></returns>
		YB_ViewItemBasis GetViewItem(int itemId) {
			string line = *(repository.GetLine(itemId));
			YB_ViewItemBasis view = YB_ViewItemBasis();
			view.Deserialize(line);
			viewitemObjectMap.insert(std::make_pair(itemId, view));
			return view;
		};


	private:
		YB_Repository repository;
		map<int, YB_ViewItemBasis> viewitemObjectMap;

		/// <summary>
		/// create view in runtime upon to a Factory Design Pattern implementation
		/// </summary>
		std::unique_ptr<YB_ViewItemBasis> CreateProduct(string viewType);

	};

}

#endif // YB_ViewItemFactory_H