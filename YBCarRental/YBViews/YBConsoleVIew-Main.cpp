// YBViews.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <locale>
#include "YB_ViewBasis.h"
#include "YB_ViewFactory.h"
#include "YB_ViewItemBasis.h"
#include "YB_ViewItemFactory.h"
#include "YB_LogicFactory.h"
#include "YB_Window.h"
#include "YBConsoleVIew-Main.h"
using namespace YBPersistence;
using namespace YBConsoleViews;


int main()
{
	//View/ViewItem serialize/deserialize unit test
		//int w = 120, h = 30;
		//YB_ViewBasis view = YB_ViewBasis(&w, &h);
		//string line = "Id:1;Title:Hello Car Rental;w:120;h:30;";
		//view.Deserialize(line);
		//cout << *view.Serialize();
		//int width = 120, height = 2;
		//YB_ViewItemBasis item = YB_ViewItemBasis(&width, &height);
		//string line = "Id:-1!x:0!y:0!w:120!h:2!isFocused:0!isSelected:0!isHidden:0!";
		//item.Deserialize(line);
		//cout << *item.Serialize();
	//View/ViewItem serialize/deserialize unit test

	//YB_ViewFactory Test
		//YB_ViewFactory viewfactory = YB_ViewFactory("E:/YB800ProSE/YBCarRental/YBCarRental/YBCar_Native_Testing/ViewRepo.txt");
		//YB_ViewBasis view = *viewfactory.GetView(1);
		//view.InitBackground('/');
		//view.Render();
		//cout << view.Title <<" - " << view.ViewType << endl;
		//cout << *view.Serialize() << endl;
		//view = *viewfactory.GetView("WelcomeView");
		//cout << view.Title <<" - " << view.ViewType << endl;
		//cout << *view.Serialize() << endl;
		//view = *viewfactory.GetView("InputView");
		//cout << view.Title <<" - " << view.ViewType << endl;
		//cout << *view.Serialize() << endl;
		//int i;
		//cin>> i;
	//YB_ViewFactory Test

	//YB_ViewItemFactory Test
		//YB_ViewItemFactory itemfactory = YB_ViewItemFactory("E:/YB800ProSE/YBCarRental/YBCarRental/YBCar_Native_Testing/ViewItemRepo.txt");
		//YB_ViewItemFactory itemfactory = YB_ViewItemFactory();
		//auto item4 = itemfactory.CreateViewItem("Id:1!x:0!y:0!w:120!h:1!ItemType:ButtonItem!Content:Yes or No!Background:/!isCentral:1!isFocused:0!isSelected:0!isHidden:0!");
		//auto item5 = itemfactory.CreateViewItem("Id:2!x:0!y:0!w:120!h:1!ItemType:TextItem!Content:The Car!Background:*!isCentral:0!isFocused:1!isSelected:0!isHidden:0!");
		//auto item6 = itemfactory.CreateViewItem("Id:3!x:0!y:0!w:50!h:1!ItemType:InputItem!Content:You and me!Background:$!isCentral:1!isFocused:1!isSelected:0!isHidden:0!");
		//if (item4 != nullptr && item5 != nullptr && item6 != nullptr) {
		//	cout << ((*item4).Serialize()->c_str()) << endl;
		//	cout << ((*item5).Serialize()->c_str()) << endl;
		//	cout << ((*item6).Serialize()->c_str()) << endl;
		//}
		//auto item1 = *itemfactory.GetViewItem(1);
		//item1.Render();
		//auto item2= *itemfactory.GetViewItem(2);
		//item2.Render();
		//auto item3= *itemfactory.GetViewItem(3);
		//item3.Render();
	//YB_ViewItemFactory Test

	//YB_ViewFactory generate children view items test
		//YB_ViewFactory factory = YB_ViewFactory("E:/YB800ProSE/YBCarRental/YBCarRental/YBCar_Native_Testing/ViewRepo.txt");
		//YB_ViewBasis view = *(factory.GetView(1));
		//auto item1 = view.subItemsMap[1];
		//auto item2 = view.subItemsMap[2];
		//auto item3 = view.subItemsMap[3];
		//(*item1).Render();
		//(*item2).Render();
		//(*item3).Render();
		//view.Init_Background(view.Background);
		//view.FillBackground(view.Background);
		//view.Render();
		//int i;
		//cin >>i;
		//system("cls");
		//view = *factory.GetView(555);
		//view.Init_Background(view.Background);
		//view.Fill_Background(',');
		//view.Render();
		//cin >>i;
	//YB_ViewFactory generate children view items test

	//YB_Window integrated test
	YB_Window window = YB_Window();
	//window.ConfigLogicFactory(xxxxLogicFactory);
	window.InitViewFactory("E:/YB800ProSE/YBCarRental/YBCarRental/YBCar_Native_Testing/ViewRepo.txt");
	window.Init();
	window.Run();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
