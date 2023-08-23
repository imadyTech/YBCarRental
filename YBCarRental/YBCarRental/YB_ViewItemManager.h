#ifndef YB_ViewItemManager_H
#define YB_ViewItemManager_H

#include "YB_User.h"
#include "YB_UserPersistor.h"
#include "YB_ManagerBasis.h"
#include "YB_ViewItemBasis.h"
using namespace YBConsoleViews;
using namespace std;

namespace YBCarRental 
{
	class YB_ViewItemManager : YB_ManagerBasis<YB_ViewItemBasis>
	{
	public:
		YB_ViewItemManager() : YB_ManagerBasis<YB_ViewItemBasis>() {};
		/// <summary>
		/// Constructor and initialization;
		/// </summary>
		/// <param name="userRepo">The file path of User Repository.</param>
		YB_ViewItemManager(string url): YB_ManagerBasis<YB_ViewItemBasis>(url) { };


		/// <summary>
		/// user registered and other properties will be initialized; 
		/// New registered user has common User role.
		/// </summary>
		/// <param name="user">user object contains name, password;  </param>
		bool UserRegister(YB_ViewItemBasis& user);



	private:
		YB_ViewItemBasis* currentUser;
	};

}

#endif // YB_ViewItemManager_H