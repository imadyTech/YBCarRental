#pragma once
#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace YBConsoleViews;

namespace YBCarTesting
{
	TEST_CLASS(YB_ViewTesting)
	{
	public:
		TEST_METHOD(YB_ViewBasis_Instantiate_Test)
		{
			int w = 64, h = 24;
			YB_ViewBasis view = YB_ViewBasis(&w, &h);
			view.Id = 999;
			string type= "LoginView";
			string source = "Hello Car Rental";
			//view.Title = new char[strlen(source) + 1];
			//strncpy_s(view.Title, strlen(source) + 1, source, strlen(source));

			view.ViewType = type;
			view.Title = source;

			string serial = *view.Serialize();
			Logger::WriteMessage(serial.c_str());
			Assert::AreEqual("Id:999;Title:Hello Car Rental;ViewType:LoginView;w:64;h:24;", serial.c_str());
		}
		TEST_METHOD(YB_ViewBasis_Deserialize_Test)
		{
			int w = 120, h = 30;
			YB_ViewBasis item = YB_ViewBasis(&w, &h);
			string line = "Id:999;Title:Hello Car Rental;ViewType:LoginView;w:120;h:30;";
			item.Deserialize(line);
			Assert::AreEqual(30, item.h);
			Assert::AreEqual(120, item.w);
			Assert::AreEqual(999, item.Id);
			Assert::AreEqual(string("Hello Car Rental"), item.Title);
			Assert::AreEqual(string("LoginView"), item.ViewType);
		}
		TEST_METHOD(YB_ViewItemBasis_Instantiate_Test)
		{
			int width = 100, height = 3;
			YB_ViewItemBasis item = YB_ViewItemBasis(width, height);
			item.Id = 101;
			item.x = 20;
			item.y = 30;
			item.isFocused = true;
			item.isHidden = false;
			item.isSelected = false;
			string serial = *item.Serialize();
			Logger::WriteMessage(serial.c_str());

			Assert::AreEqual("Id:101!x:20!y:30!w:100!h:3!isFocused:1!isSelected:0!isHidden:0!", serial.c_str());
		}
		TEST_METHOD(YB_ViewItemBasis_Deserialize_Test)
		{
			int width = 120, height = 2;
			YB_ViewItemBasis item = YB_ViewItemBasis(width, height);
			string line = "Id:-1!x:0!y:0!w:120!h:2!isFocused:0!isSelected:1!isHidden:0!";
			item.Deserialize(line);
			Assert::AreEqual(120, item.w);
			Assert::AreEqual(2, item.h);
			Assert::AreEqual(false, item.isFocused);
			Assert::AreEqual(true, item.isSelected);
		}




	};
}