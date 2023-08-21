#pragma once
#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace YBCarRental;

namespace YBCarTesting
{
	TEST_CLASS(YBCar_ManagerTesting)
	{
	public:
		TEST_METHOD(YB_GetAllUser_Test)
		{}

		TEST_METHOD(YB_IsAdminTest)
		{
			YB_UserManager mgr = YB_UserManager("E:/YB800ProSE/YBCarRental/YBCarRental/YBCar_Native_Testing/UserRepo.txt");
			mgr.UserLogin("fshen", "666666");
			Assert::AreEqual(false, mgr.IsAdmin());
			mgr.UserLogout();
			mgr.UserLogin("admin", "666666");
			Assert::AreEqual(true, mgr.IsAdmin());
			mgr.UserLogout();
		}
	};
}