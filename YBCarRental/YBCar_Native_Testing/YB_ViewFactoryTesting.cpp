#pragma once
#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace YBConsoleViews;

namespace YBCarTesting
{
	TEST_CLASS(YB_ViewFactory_Testing)
	{
	public:
		TEST_METHOD(YB_ViewFactory_Init_Test)
		{
			YB_ViewFactory factory = YB_ViewFactory("E:/YB800ProSE/YBCarRental/YBCarRental/YBCar_Native_Testing/ViewRepo.txt");
			YB_ViewBasis view1 = *(factory.GetView(999));
			YB_ViewBasis view2 = *(factory.GetView(111));

			Assert::AreEqual(string("Hello Car Rental"), view1.Title);
			Assert::AreEqual(string("Please Login"), view2.Title);
			Assert::AreEqual(string("WelcomeView"), view1.ViewType);
			Assert::AreEqual(string("LoginView"), view2.ViewType);
		}
		TEST_METHOD(GetView_byType_Test)
		{
			YB_ViewFactory factory = YB_ViewFactory("E:/YB800ProSE/YBCarRental/YBCarRental/YBCar_Native_Testing/ViewRepo.txt");
			YB_ViewBasis view = *(factory.GetView("WelcomeView"));
			Assert::AreEqual(string("Hello Car Rental"), view.Title);
			Assert::AreEqual(string("WelcomeView"), view.ViewType);

		}

	};
}