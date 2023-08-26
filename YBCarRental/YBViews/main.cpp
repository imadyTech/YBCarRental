// YBViews.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <locale>
#include "YB_ViewBasis.h"
using namespace YBPersistence;
using namespace YBConsoleViews;
int main()
{
	//int w = 120, h = 30;
	//YB_ViewBasis view = YB_ViewBasis(&w, &h);
	//string line = "Id:1;Title:Hello Car Rental;w:120;h:30;";
	//view.Deserialize(line);

	//cout << *view.Serialize();


	int width = 120, height = 2;
	YB_ViewItemBasis item = YB_ViewItemBasis(&width, &height);
	string line = "Id:-1!x:0!y:0!w:120!h:2!isFocused:0!isSelected:0!isHidden:0!";
	item.Deserialize(line);

	cout << *item.Serialize();

	//cin;
	//std::wcout << L"** Unicode Characters: \u221A \u2302 \u25A1" << std::endl;

	//char* p = new char[200];
	//strcpy_s(p,11, "hellohello");
	//cout <<&p<<":"<< p << ";" << endl;
	//strcpy_s(p+2,5, "yoyo");
	//cout <<&p<<":"<< p << ";"<< endl;

	//cout << *p << endl;

	//char* s = new char[60];
	//std::fill(s, s + 20, '*');
	//s[20]= '\0';

	//cout << s << endl;

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
