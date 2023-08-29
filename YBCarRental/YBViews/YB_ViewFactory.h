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
#include "YB_ViewItemFactory.h"

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
		void LoadAllViews();

		YB_ViewBasis* GetView(int viewId);
		YB_ViewBasis* GetView(string viewType);


	private:
		std::map<int, YB_ViewBasis>		viewPool;
		YBPersistence::YB_Repository	repository;
		YB_ViewItemFactory				viewItemFactory;

		/// <summary>
		/// create view in runtime using Factory Design Pattern implementation
		/// </summary>
		std::unique_ptr<YB_ViewBasis>	CreateProduct(const string serializeString);
		void							CreateViewitem(YB_ViewBasis* view, const string viewString);

		//get the value based on viewType keyword
		//std::string FindType(std::string serializeString);
	};
}

#endif // YB_ViewFactory_H