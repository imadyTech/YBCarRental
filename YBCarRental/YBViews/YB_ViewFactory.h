#ifndef YB_ViewFactory_H
#define YB_ViewFactory_H

#include "YB_Repository.h"
#include "YB_ViewBasis.h"
#include <YB_Errors.h>

using namespace std;
using namespace YBPersistence;

namespace YBConsoleViews
{
	class YB_ViewFactory
	{
	public:
		/// <summary>
		/// Constructor and initialization (read view YBML into repository).
		/// </summary>
		/// <param name="viewRepoUrl">The file path of View Repository (view definitions similar function to HTML).</param>
		YB_ViewFactory(string viewRepoUrl) {
			repository = YB_Repository(viewRepoUrl);
			LoadAllViews();
		};

		/// <summary>
		/// objectize all text def in repo to YB_View objects
		/// </summary>
		void LoadAllViews()
		{
			if (!this->repository.isReady)
				throw YB_RepositoryError();			//It is not allowed if never ReadAllLines().

			for (auto& pairValue : repository.allRecordLines)
			{
				YB_ViewBasis view = YB_ViewBasis();
				try
				{
					view.Deserialize(pairValue.second);
					viewPool.insert(std::make_pair(pairValue.first, view));
				}
				catch (exception e)
				{
					throw YB_FactoryError();
				}
			}
		}

		/// <summary>
		/// Find the view through search the Title of view (make sure view.Title has no overlap. No conflict check mechanism in this project.)
		/// </summary>
		/// <param name="viewTitle"></param>
		/// <returns></returns>
		YB_ViewBasis* GetBasisView(int viewId) {
			auto iterator = viewPool.find(viewId);
			if (iterator != viewPool.end())
			{
				return &iterator->second;
			}
			else
				return nullptr;
		}

		YB_ViewBasis* GetBasisView(string viewType) {
			for (auto& iterator : viewPool)
			{
				if (iterator.second.ViewType == viewType)
				{
					return &(iterator.second);
				}
			}
			return nullptr;
		};


	private:
		YB_Repository repository;

		map<int, YB_ViewBasis> viewPool;

		/// <summary>
		/// create view in runtime upon to a Factory Design Pattern implementation
		/// </summary>
		std::unique_ptr<YB_ViewBasis> CreateProduct(string viewType);
	};
}

#endif // YB_ViewFactory_H