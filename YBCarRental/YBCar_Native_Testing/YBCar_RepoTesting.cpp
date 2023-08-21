#pragma once
#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace YBCarRental;

namespace YBCarTesting
{
	TEST_CLASS(YBCar_RepoTesting)
	{
	public:
		TEST_METHOD(YB_IsRepoReady_Test)
		{
			//YB_Repository repo = YB_Repository("UserRepo.txt"); //Error, not read the file
			YB_Repository repo = YB_Repository("E:/YB800ProSE/YBCarRental/YBCarRental/YBCar_Native_Testing/UserRepo.txt");
			Assert::IsTrue(repo.isReady);
		}
		TEST_METHOD(YB_ReadAllLines_Test)
		{
			//YB_Repository repo = YB_Repository("UserRepo.txt"); //Error, not read the file
			YB_Repository repo = YB_Repository("E:/YB800ProSE/YBCarRental/YBCarRental/YBCar_Native_Testing/UserRepo.txt");
			repo.ReadAllLines();

			int index = 15;
			string record =* repo.GetLine(index);
			string expected = "15;fshen;0;Frank;Shen;666666;10000;user;";
			Assert::AreEqual(expected, record);

			index = 16;
			expected = "16;admin;0;Noman;AI;666666;0;user|admin;";
			Assert::AreEqual(expected, *repo.GetLine(index));
		}

		TEST_METHOD(YB_AddLine_Test)
		{
			YB_Repository repo = YB_Repository("E:/YB800ProSE/YBCarRental/YBCarRental/YBCar_Native_Testing/UserRepo.txt");
			repo.ReadAllLines();
			repo.AddLine("17;superman;0;Super;Man;666666;999;user;");

			int index = 17;
			string record =* repo.GetLine(index);
			string expected = "17;superman;0;Super;Man;666666;999;user;";
			Assert::AreEqual(expected, record);
		}
		TEST_METHOD(YB_DeleteLine_Test)
		{
			YB_Repository repo = YB_Repository("E:/YB800ProSE/YBCarRental/YBCarRental/YBCar_Native_Testing/UserRepo.txt");
			repo.ReadAllLines();
			//make sure the line with index number 17 already exist
			int index = 17;
			repo.DeleteLine(index);

			string* record = repo.GetLine(index);
			
			Assert::IsNull(record);
		}
		TEST_METHOD(YB_UpdateLine_Test)
		{
			YB_Repository repo = YB_Repository("E:/YB800ProSE/YBCarRental/YBCarRental/YBCar_Native_Testing/UserRepo.txt");
			repo.ReadAllLines();
			//make sure the line with index number 17 already exist
			string expected = "17;superMan;1;Super;Man;666666;0;user;";
			repo.UpdateLine(expected);
			string* record = repo.GetLine(17);
			
			Assert::AreEqual(expected, *record);
		}
	};
}