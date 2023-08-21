#pragma once
#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace YBCarRental;

namespace YBCarTesting
{
	TEST_CLASS(YBCar_PersistorTesting)
	{
	public:
		TEST_METHOD(YB_GetAllUser_Test)
		{
			YB_PersistorBasis<YB_User> persistor = YB_PersistorBasis<YB_User>("E:/YB800ProSE/YBCarRental/YBCarRental/YBCar_Native_Testing/UserRepo.txt");
			persistor.GetAll();

			for (const auto& item : persistor.dataSet)
			{
				Logger::WriteMessage((item.second.Id + " " + item.second.UserName + " " + item.second.Password + "\n").c_str());
			}
			YB_User user = persistor.dataSet.find(18)->second;
			string firstName = "No", familyName = "Body", userName = "Nobody";
			Assert::AreEqual(firstName, user.FirstName);
			Assert::AreEqual(familyName, user.FamilyName);
			Assert::AreEqual(userName, user.UserName);
			Assert::AreEqual(4, static_cast<int>(persistor.dataSet.size()));
		}

		TEST_METHOD(YB_GetUser_Test)
		{
			YB_PersistorBasis<YB_User> persistor = YB_PersistorBasis<YB_User>("E:/YB800ProSE/YBCarRental/YBCarRental/YBCar_Native_Testing/UserRepo.txt");
			YB_User user = YB_User();
			persistor.Get(15, &user);

			Logger::WriteMessage((user.Id + " / " + user.UserName + " / " + user.Password + "\n").c_str());
			string firstName = "Frank", familyName = "Shen";
			Assert::AreEqual(firstName, user.FirstName);
			Assert::AreEqual(familyName, user.FamilyName);
		}

		TEST_METHOD(YB_GetUser_Test1)
		{
			YB_PersistorBasis<YB_User> persistor = YB_PersistorBasis<YB_User>("E:/YB800ProSE/YBCarRental/YBCarRental/YBCar_Native_Testing/UserRepo.txt");
			YB_User* user;
			user = persistor.Get(15);

			Logger::WriteMessage(((*user).Id + " / " + (*user).UserName + " / " + (*user).Password + "\n").c_str());
			string firstName = "Frank", familyName = "Shen";
			Assert::AreEqual(firstName, (*user).FirstName);
			Assert::AreEqual(familyName, (*user).FamilyName);
		}

		TEST_METHOD(YB_AddUser_Test)
		{
			YB_PersistorBasis<YB_User> persistor = YB_PersistorBasis<YB_User>("E:/YB800ProSE/YBCarRental/YBCarRental/YBCar_Native_Testing/UserRepo.txt");
			YB_User user = YB_User();
			user.Deserialize("18;Nobody;0;No;Body;666666;111;user;");
			persistor.Add(user);

			YB_User user1 = YB_User();
			persistor.Get(18, &user1);
			string firstName = "No", familyName = "Body";
			Assert::AreEqual(firstName, user1.FirstName);
			Assert::AreEqual(familyName, user1.FamilyName);
		}

		TEST_METHOD(YB_UpdateUser_Test)
		{
			YB_PersistorBasis<YB_User> persistor = YB_PersistorBasis<YB_User>("E:/YB800ProSE/YBCarRental/YBCarRental/YBCar_Native_Testing/UserRepo.txt");
			//before test, make sure there is a line of record with id=18
			YB_User user;
			persistor.Get(18, &user);
			user.FirstName = "Have";
			user.FamilyName = "Some";
			persistor.Update(user);

			string firstName = "Have", familyName = "Some";
			YB_User* user1 = persistor.Get(18);
			Assert::AreEqual(firstName, (*user1).FirstName);
			Assert::AreEqual(familyName, (*user1).FamilyName);
		}

		TEST_METHOD(YB_DelUser_Test)
		{
			YB_PersistorBasis<YB_User> persistor = YB_PersistorBasis<YB_User>("E:/YB800ProSE/YBCarRental/YBCarRental/YBCar_Native_Testing/UserRepo.txt");
			//before test, make sure there is a line of record with id=18
			bool result = persistor.Delete(18);
			Assert::IsTrue(result);
			//if successfully deleted, Get will return a nullptr
			YB_User* userPtr = persistor.Get(18);
			Assert::IsNull(userPtr);
		}

		TEST_METHOD(YB_FindUserName_Test)
		{
			YB_PersistorBasis<YB_User> persistor = YB_PersistorBasis<YB_User>("E:/YB800ProSE/YBCarRental/YBCarRental/YBCar_Native_Testing/UserRepo.txt");
			//before test, make sure there is a line of record with id=15
			YB_User * user = persistor.Get("fshen");
			string firstName = "Frank", familyName = "Shen";
			Assert::AreEqual(firstName, (*user).FirstName);
			Assert::AreEqual(familyName, (*user).FamilyName);
		}
	};
}