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
		TEST_METHOD(YB_RepoReadAllLines_Test)
		{
			YB_Repository repo = YB_Repository("UserRepo.txt");
			repo.ReadAllLines();
			int index = 15;
			string record =* repo.GetLine(index);
			string expected = "15;fshen;0;Frank;Shen;666666;10000;user;";
			Assert::AreEqual(expected, record);
			//mgr.UserLogout();

		}
	};
}