#pragma once
#include "pch.h"
#include "CppUnitTest.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace YBCarRental;

namespace YBCarNativeTesting
{
	TEST_CLASS(YBCarNativeTesting)
	{
	public:

		TEST_METHOD(YB_UserPersistorTest)
		{
			//Testing the persistors and how C++ template class and method works.
			//YB_User user = YB_User();       //OK
			//YB_PersistorBasis<YB_DataBasis> userPersistor = YB_PersistorBasis<YB_DataBasis>(); //Not tested
			//YB_PersistorBasis<YB_User> userPersistor = YB_PersistorBasis<YB_User>("This is where the data stored.");  //OK
			YBCarRental::YB_UserPersistor userPersistor = YBCarRental::YB_UserPersistor("This is where the user data stored."); //OK
			cout << userPersistor.repositoryURL << endl;
			Assert::AreEqual("This is where the user data stored.", userPersistor.repositoryURL.c_str());
		}

		TEST_METHOD(YB_UserTest)
		{
			//OK
			YB_User user = YB_User();
			user.FirstName = "Frank";
			user.FamilyName = "Shen";
			user.Id = 15;
			user.Password = "666666";
			user.UserName = "fshen";
			user.LoginStatus = false;
			user.UserRoles = "user:admin";
			user.Balance = 10000;
			//OK

			Assert::AreEqual("Frank", user.FirstName.c_str());
		}
	};
}
