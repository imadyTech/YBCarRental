#include "YB_User.h"
#include "YB_UserManager.h"

namespace YBCarRental
{
	//YB_UserManager::YB_UserManager()
	//{
	//}
	//YB_UserManager::YB_UserManager(string userRepo)
	//{
	//}
	//;
	bool YB_UserManager::UserRegister(YB_User& user)
	{
		auto existingUser = this->Get(user.Id);
		if (existingUser != nullptr)
		{
			return false; //user already exist
		}
		bool result = this->Add(user);
		
		return result;
	}
	bool YB_UserManager::UserLogin(string username, string password)
	{
		return false;
	}
	bool YB_UserManager::UserLogout()
	{
		return false;
	}
	bool YB_UserManager::IsAdmin()
	{
		return false;
	}
	;
}