#include "YB_User.h"
#include "YB_UserManager.h"

namespace YBCarRental
{
	bool		YBCarRental::YB_UserManager::UserRegister(YB_User& user)
	{
		auto existingUser = YB_ManagerBasis::Get(user.Id);
		if (existingUser != nullptr)
		{
			return false; //user already exist
		}
		return this->Add(user);
	}

	bool		YBCarRental::YB_UserManager::UserLogin(string username, string password)
	{
		YB_User* userPtr = this->Get(username);
		if (userPtr && userPtr->Password == password)
		{
			userPtr->LoginStatus = true;
			this->Update(*userPtr);
			currentUser = userPtr;
			return true;
		}
		else
			return false;
	}

	bool		YBCarRental::YB_UserManager::UserLogout()
	{
		currentUser->LoginStatus = false;

		if (this->Update(*currentUser))
			return true;
		else
			return false;
	}

	bool		YBCarRental::YB_UserManager::IsAdmin()
	{
		return currentUser->UserRoles.find("admin") != std::string::npos;
	}

	YB_User*	YBCarRental::YB_UserManager::Get(string username)
	{
		int id = -1;
		auto all = YB_ManagerBasis::GetAll();
		for (auto& entry : *all) {
			//data = entry.second;
			if (entry.second.UserName == username) {
				//as the entry was created in the for loop, so it will be destructed after for loop breaks.
				//int value will be copied so it won't loss.
				id = entry.second.Id;
				break;
			}
		}
		return persistor->Get(id);
	}

	YB_User*	YBCarRental::YB_UserManager::CurrentUser()
	{
		return currentUser;
	};
}