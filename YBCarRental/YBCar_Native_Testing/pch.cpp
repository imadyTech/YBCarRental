// pch.cpp: source file corresponding to the pre-compiled header
#include "pch.h"
// When you are using pre-compiled headers, this source file is necessary for compilation to succeed.


using namespace YBCarRental;

namespace YBCarTesting
{
	//---------------Private methods of testing context----------------
	YB_User CreateSimulativeNormalUser()
	{
		//OK
		YB_User user = YB_User();
		user.FirstName = "Frank";
		user.FamilyName = "Shen";
		user.Id = 15;
		user.Password = "666666";
		user.UserName = "fshen";
		user.LoginStatus = false;
		user.UserRoles = "user";
		user.Balance = 10000;
		//OK
		return user;
	}
	YB_User CreateSimulativeAdminUser()
	{
		//OK
		YB_User user = YB_User();
		user.FirstName = "Noman";
		user.FamilyName = "AI";
		user.Id = 16;
		user.Password = "666666";
		user.UserName = "admin";
		user.LoginStatus = false;
		user.UserRoles = "user|admin";
		user.Balance = 0;
		//OK
		return user;
	}

}