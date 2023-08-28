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
		TEST_METHOD(ViewFactory_Test)
		{
			YB_ViewFactory factory = YB_ViewFactory("E:/YB800ProSE/YBCarRental/YBCarRental/YBCar_Native_Testing/ViewRepo.txt");
			YB_ViewBasis view = *factory.GetViewItem(999);
			view.InitBackground('/');
			view.Render();
			//cout << view.Title << " - " << view.ViewType << endl;
			//cout << *view.Serialize() << endl;
			view = *factory.GetViewItem("WelcomeView");
			//cout << view.Title << " - " << view.ViewType << endl;
			//cout << *view.Serialize() << endl;
			view = *factory.GetViewItem("InputView");
			//cout << view.Title << " - " << view.ViewType << endl;
			//cout << *view.Serialize() << endl;
		}
		TEST_METHOD(YB_ViewFactory_Init_Test)
		{
			YB_ViewFactory factory = YB_ViewFactory("E:/YB800ProSE/YBCarRental/YBCarRental/YBCar_Native_Testing/ViewRepo.txt");
			YB_ViewBasis view1 = *(factory.GetViewItem(999));
			YB_ViewBasis view2 = *(factory.GetViewItem(111));

			Assert::AreEqual(string("Hello Car Rental"), view1.Title);
			Assert::AreEqual(string("Please Login"), view2.Title);
			Assert::AreEqual(string("WelcomeView"), view1.ViewType);
			Assert::AreEqual(string("LoginView"), view2.ViewType);
		}
		TEST_METHOD(YB_ViewItemFactory_Init_Test)
		{
			YB_ViewItemFactory factory = YB_ViewItemFactory();
			YB_ViewItemBasis item1 = 
				*(factory.CreateViewItem("Id:-1!x:0!y:0!w:120!h:1!ItemType:ButtonItem!Content:!Background:.!isCentral:1!isFocused:0!isSelected:0!isHidden:0!"));
			YB_ViewItemBasis item2 =
				*(factory.CreateViewItem("Id:-1!x:0!y:0!w:120!h:1!ItemType:TextItem!Content:!Background:-!isCentral:1!isFocused:0!isSelected:0!isHidden:0!"));

			
			//Logger::WriteMessage(item1.Serialize()->c_str());
			//Logger::WriteMessage(item2.Serialize()->c_str());
			//Assert::AreEqual(string("Hello Car Rental"), view1.Title);
			//Assert::AreEqual(string("Please Login"), view2.Title);
			//Assert::AreEqual(string("WelcomeView"), view1.ViewType);
			//Assert::AreEqual(string("LoginView"), view2.ViewType);
		}
		TEST_METHOD(GetView_byType_Test)
		{
			YB_ViewFactory factory = YB_ViewFactory("E:/YB800ProSE/YBCarRental/YBCarRental/YBCar_Native_Testing/ViewRepo.txt");
			YB_ViewBasis view = *(factory.GetViewItem("WelcomeView"));
			Assert::AreEqual(string("Hello Car Rental"), view.Title);
			Assert::AreEqual(string("WelcomeView"), view.ViewType);

		}

	};
}