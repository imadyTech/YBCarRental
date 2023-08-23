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
	class YB_ViewManager : YB_ManagerBasis<YB_ViewBasis>
	{
	public:
		YB_ViewManager() : YB_ManagerBasis<YB_ViewBasis>() {};
		/// <summary>
		/// Constructor and initialization;
		/// </summary>
		/// <param name="userRepo">The file path of User Repository.</param>
		YB_ViewManager(string url): YB_ManagerBasis<YB_ViewBasis>(url) { };



	private:
		YB_ViewBasis* currentUser;
	};

}

#endif // YB_ViewManager_H