#ifndef YB_UserManager_H
#define YB_UserManager_H

#include "YB_User.h"
#include "YB_UserPersistor.h"
#include "YB_ManagerBasis.h"

using namespace std;

namespace YBCarRental 
{
	class YB_UserManager: YB_ManagerBasis<YB_User>
	{
	public:
		YB_UserManager() : YB_ManagerBasis<YB_User>() {};
		/// <summary>
		/// Constructor and initialization;
		/// </summary>
		/// <param name="userRepo">The file path of User Repository.</param>
		YB_UserManager(string url): YB_ManagerBasis<YB_User>(url) { };


		/// <summary>
		/// user registered and other properties will be initialized; 
		/// New registered user has common User role.
		/// </summary>
		/// <param name="user">user object contains name, password;  </param>
		bool UserRegister(YB_User& user);

		/// <summary>
		/// User login with name/psd association;
		/// User successfully logged in will replace the value of 'CurrentUser';
		/// </summary>
		/// <param name="username"></param>
		/// <param name="password"></param>
		/// <returns>True: success; False: error</returns>
		bool UserLogin(string username, string password);

		/// <summary>
		/// Log out current user
		/// </summary>
		/// <returns>True: success; False: error</returns>
		bool UserLogout();

		/// <summary>
		/// Return true/false of whether user currently logged in has the administrative role.
		/// </summary>
		/// <returns></returns>
		bool IsAdmin();

	private:
		YB_User* currentUser;
	};

}

#endif YB_UserManager_H