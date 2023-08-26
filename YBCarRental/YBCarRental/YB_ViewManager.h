#ifndef YB_ViewManager_H
#define YB_ViewManager_H

#include "YB_User.h"
#include "YB_UserPersistor.h"
#include "YB_ManagerBasis.h"
#include "YB_ViewBasis.h"

using namespace std;
using namespace YBConsoleViews;

namespace YBCarRental 
{
	class YB_ViewManager : protected YB_ManagerBasis<YB_ViewBasis>
	{
	public:
		YB_ViewManager() : YB_ManagerBasis<YB_ViewBasis>() {};
		/// <summary>
		/// Constructor and initialization;
		/// </summary>
		/// <param name="userRepo">The file path of View Repository (view definitions similar function to HTML).</param>
		YB_ViewManager(string url): YB_ManagerBasis<YB_ViewBasis>(url) { };

		void LoadAllViews();			

	private:
		//YB_ViewBasis* currentView;
	};



	/// <summary>
	/// this is a sample of Factory Design Pattern
	/// </summary>
	class ProductFactory {
	public:
		std::unique_ptr<YB_ViewBasis> createProduct(char productType) {
			switch (productType) {
			case 'A':
				return std::make_unique<YB_ViewBasis>();
			case 'B':
				return std::make_unique<YB_ViewBasis>();
			default:
				return nullptr;
			}
		}
	};
}

#endif // YB_ViewManager_H