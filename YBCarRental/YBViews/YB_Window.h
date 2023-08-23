#ifndef YB_Window_H
#define YB_Window_H
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <iostream>
#include "YB_ViewBasis.h"

using namespace std;

namespace YBConsoleViews
{
	class YB_Window
	{
	public:
		vector<char*>* background;

		void GetKeyInput();
		//void ResponseInput();
		void RenderView();
		void Goto(char* viewId);						//Activate a view
		void Prev();
		void Next();

		void AddView(YB_ViewBasis view);	
	private:
		YB_ViewBasis currentView;
		map<char*, YB_ViewBasis> viewCollection;
		stack<YB_ViewBasis> viewStack;
	};
}
#endif