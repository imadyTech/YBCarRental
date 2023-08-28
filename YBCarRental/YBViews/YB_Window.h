#ifndef YB_Window_H
#define YB_Window_H
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <iostream>
#include "YB_ViewBasis.h"
#include "YB_ViewFactory.h"
#include "YB_ViewItemFactory.h"

using namespace std;

namespace YBConsoleViews
{
	class YB_Window
	{
	public:
		YB_Window() = default;

		//======================Key and processor=========================
		// F9:				Window
		// Esc:				View
		// Tab:				View
		// Backspace:		ViewItem
		// Num:				ViewItem
		// Alphabete:		ViewItem
		// Space:			ViewItem
		//================================================================
		void OnKeyIn();

		void Render();								//view contents
		void Goto(int viewId);						//Activate a view
		void Prev();
		void Next();
		void Output();								//to screen
	private:
		YB_ViewFactory				viewFactory;
		YB_ViewItemFactory			viewItemFactory;
		YB_ViewBasis				currentView;
		map<int, YB_ViewBasis>		viewCollection;
		stack<YB_ViewBasis>			viewStack;
	};

}
#endif // YB_Window_H