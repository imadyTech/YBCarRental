#pragma once
#include "pch.h"
#include "CppUnitTest.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace YBCarRental;

namespace YBCarTesting
{
	TEST_CLASS(YBCar_UserTesting)
	{
	public:
		TEST_METHOD(YB_UserRegisterTest)
		{
			YB_UserManager mgr = YB_UserManager("This is where the user data stored.");
			YB_User user = CreateSimulativeNormalUser();
			
			Assert::AreEqual(false, mgr.UserRegister(user));
			//mgr.UserLogout();

		}

		TEST_METHOD(YB_UserManagerTest)
		{
			YB_UserManager mgr = YB_UserManager("This is where the user data stored.");
			YB_User user = CreateSimulativeNormalUser();
			mgr.UserLogin(user.UserName, user.Password);
			Assert::AreEqual(false, mgr.IsAdmin());
			mgr.UserLogout();

			YB_User admin = CreateSimulativeAdminUser();
			mgr.UserLogin(admin.UserName, admin.Password);
			Assert::AreEqual(true, mgr.IsAdmin());

		}
		TEST_METHOD(YB_UserDeserielizeTest)
		{
			string test = "15;fshen;0;Frank;Shen;666666;10000;user;";
			YB_User user = YB_User();
			user.Deserialize(test);
			Assert::AreEqual("Frank", user.FirstName.c_str());
			Assert::AreEqual("fshen", user.UserName.c_str());
			Assert::AreEqual(15, user.Id);

		}
		TEST_METHOD(YB_UserSerielizeTest)
		{
			string expect = "15;fshen;0;Frank;Shen;666666;10000;user;";
			YB_User user = CreateSimulativeNormalUser();
			string result = *user.Serialize();
			cout << result;
			Assert::AreEqual(expect, result);
		}
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
			YB_User user= CreateSimulativeNormalUser();
			//OK

			Assert::AreEqual("Frank", user.FirstName.c_str());
		}


	};
}
