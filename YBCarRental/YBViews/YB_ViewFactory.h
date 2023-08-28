#ifndef YB_ViewFactory_H
#define YB_ViewFactory_H

#include "YB_Repository.h"
#include "YB_ViewBasis.h"
#include <YB_Errors.h>
#include "YB_InputView.h"
#include "YB_MenuView.h"
#include "YB_WelcomeView.h"
#include "YB_DetailsView.h"
#include "YB_DialogView.h"
#include "YB_ListView.h"

using namespace std;
using namespace YBPersistence;

namespace YBConsoleViews
{
	typedef YBConsoleViews::YB_MenuView			MenuView;
	typedef YBConsoleViews::YB_WelcomeView		WelcomeView;
	typedef YBConsoleViews::YB_InputView		InputView;
	typedef YBConsoleViews::YB_DialogView		DialogView;
	typedef YBConsoleViews::YB_ListView			ListView;
	typedef YBConsoleViews::YB_DetailsView		DetailsView;


	class YB_ViewFactory
	{
	public:
		YB_ViewFactory() {};
		/// <summary>
		/// Constructor and initialization (read view YBML into repository).
		/// </summary>
		/// <param name="viewRepoUrl">The file path of View Repository (view definitions similar function to HTML).</param>
		YB_ViewFactory(string viewRepoUrl):YB_ViewFactory() {
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
				std::unique_ptr<YB_ViewBasis> viewPtr = this->CreateProduct(pairValue.second); //Pass the view serializeString
				YB_ViewBasis* view = viewPtr.get();
				try
				{
					(*view).Deserialize(pairValue.second);										//deserialize String
					viewPool.insert(std::make_pair(pairValue.first, *view));
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
		YB_ViewBasis* GetView(int viewId) {
			auto iterator = viewPool.find(viewId);
			if (iterator != viewPool.end())
			{
				return &(iterator->second);
			}
			else
				return nullptr;
		}

		YB_ViewBasis* GetView(string viewType) {
			for (auto& iterator : viewPool)
			{
				if ((iterator.second).ViewType == viewType)
				{
					return &iterator.second;
				}
			}
			return nullptr;
		};


	private:
		std::map<int, YB_ViewBasis>		viewPool;
		YBPersistence::YB_Repository	repository;

		/// <summary>
		/// create view in runtime using Factory Design Pattern implementation
		/// </summary>
		std::unique_ptr<YB_ViewBasis>	CreateProduct(string serializeString);

		//get the value based on viewType keyword
		//std::string FindType(std::string serializeString);
	};
}

#endif // YB_ViewFactory_H