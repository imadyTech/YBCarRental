#include "YB_User.h"
#include "YB_UserManager.h"

namespace YBCarRental
{
	bool YB_UserManager::UserRegister(YB_User& user)
	{
		auto existingUser = this->Get(user.Id);
		if (existingUser != nullptr)
		{
			return false; //user already exist
		}
		return this->Add(user);
	}


	bool YB_UserManager::UserLogin(string username, string password)
	{
		YB_User* userPtr = this->Get(username);
		if (userPtr->Password == password)
		{
			userPtr->LoginStatus = true;
			this->Update(*userPtr);
			currentUser = userPtr;
			return true;
		}
		else
			return false;
	}


	bool YB_UserManager::UserLogout()
	{
		currentUser->LoginStatus = false;

		if (this->Update(*currentUser))
			return true;
		else
			return false;
	}


	bool YB_UserManager::IsAdmin()
	{
		return currentUser->UserRoles.find("admin") != std::string::npos;
	};
}