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
			YB_ViewBasis view = *factory.GetView(1);
			view.Init_Background('/');
			view.Render();
			//cout << view.Title << " - " << view.ViewType << endl;
			//cout << *view.Serialize() << endl;
			view = *factory.GetView("WelcomeView");
			//cout << view.Title << " - " << view.ViewType << endl;
			//cout << *view.Serialize() << endl;
			view = *factory.GetView("InputView");
			//cout << view.Title << " - " << view.ViewType << endl;
			//cout << *view.Serialize() << endl;
		}
		TEST_METHOD(YB_ViewFactory_Init_Test)
		{
			YB_ViewFactory factory = YB_ViewFactory("E:/YB800ProSE/YBCarRental/YBCarRental/YBCar_Native_Testing/ViewRepo.txt");
			YB_ViewBasis view1 = *(factory.GetView(1));
			YB_ViewBasis view2 = *(factory.GetView(111));

			Assert::AreEqual(string("Hello Car Rental"), view1.Title);
			Assert::AreEqual(string("Please Login"), view2.Title);
			Assert::AreEqual(string("WelcomeView"), view1.ViewType);
			Assert::AreEqual(string("InputView"), view2.ViewType);
		}
		TEST_METHOD(YB_ViewItemFactory_Init_Test)
		{
			YB_ViewItemFactory itemfactory = YB_ViewItemFactory();
			YB_ViewItemBasis* item1 = itemfactory.CreateViewItem("Id:1!x:0!y:0!w:30!h:1!ItemType:ButtonItem!Content:Yes or No!Background:/!isCentral:1!isFocused:0!isSelected:0!isHidden:0!");
			YB_ViewItemBasis* item2 = itemfactory.CreateViewItem("Id:2!x:0!y:0!w:40!h:1!ItemType:TextItem!Content:The Car!Background:*!isCentral:0!isFocused:1!isSelected:0!isHidden:0!");
			YB_ViewItemBasis* item3 = itemfactory.CreateViewItem("Id:3!x:0!y:0!w:50!h:1!ItemType:InputItem!Content:You and me!Background:$!isCentral:1!isFocused:1!isSelected:0!isHidden:0!");

			Logger::WriteMessage((*item1).Serialize()->c_str());
			Logger::WriteMessage((*item2).Serialize()->c_str());
			Logger::WriteMessage((*item3).Serialize()->c_str());

			Assert::AreEqual(string("Yes or No"),				(*item1).Content);
			Assert::AreEqual(string("The Car"),					(*item2).Content);
			Assert::AreEqual(string("You and me"),				(*item3).Content);
			Assert::AreEqual(string("ButtonItem"),				(*item1).ItemType);
			Assert::AreEqual(string("TextItem"),				(*item2).ItemType);
			Assert::AreEqual(string("InputItem"),				(*item3).ItemType);
		}
		
		TEST_METHOD(GetSingleView_Test)
		{
			YB_ViewFactory factory = YB_ViewFactory("E:/YB800ProSE/YBCarRental/YBCarRental/YBCar_Native_Testing/ViewItemRepo.txt");
			YB_ViewBasis view = *(factory.GetView("LoginView"));
			Assert::AreEqual(string("LoginView"), view.Title);
			Assert::AreEqual(string("InputView"), view.ViewType);
		}

		TEST_METHOD(GetView_withChildren_Test)
		{
			YB_ViewFactory factory = YB_ViewFactory("E:/YB800ProSE/YBCarRental/YBCarRental/YBCar_Native_Testing/ViewRepo.txt");
			YB_ViewBasis view = *(factory.GetView(555));
			//Caution: subItemsMap is a map instead of vector. Donot query some key unexisted.
			auto item1 = view.subItemsList[1];
			auto item2 = view.subItemsList[2];
			auto item3 = view.subItemsList[3];

			Assert::AreEqual(string("Yes or No"),	(*item1).Content);
			Assert::AreEqual(string("The Car"),		(*item2).Content);
			Assert::AreEqual(string("You and me"),	(*item3).Content);
			Assert::AreEqual(string("ButtonItem"),	(*item1).ItemType);
			Assert::AreEqual(string("TextItem"),	(*item2).ItemType);
			Assert::AreEqual(string("InputItem"),	(*item3).ItemType);
		}
	};
}