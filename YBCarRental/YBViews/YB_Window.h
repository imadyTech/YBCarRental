#ifndef YB_Window_H
#define YB_Window_H
#include <stack>
//#include <vector>
//#include <map>
#include <string>
#include <conio.h>
//#include <iostream>
#include "YB_ViewBasis.h"
#include "YB_ViewFactory.h"
#include <windows.h>
//#include "YB_ViewItemFactory.h"

using namespace std;

namespace YBConsoleViews
{
	class YB_Window
	{
	public:
		YB_Window() = default;

		void InitViewFactory(string viewRepo);

		//==========================Key and processor=============================
		// F9:			Window		Keycode: 120	GetAsyncKeyState(VK_F9) & 0x8000
		// Esc:			View		Keycode: 27
		// Tab:			View		Keycode: 9
		// Backspace:	ViewItem	Keycode: 8
		// Num:			ViewItem	Keycode: 48-57
		// Alphabete:	ViewItem	Keycode: 65-90, 97-122
		// Spacce:		ViewItem	Keycode: 32		GetAsyncKeyState(VK_SPACE) & 0x8000
		// Delete:		ViewItem	Keycode: 46
		//========================================================================

		void Init();
		void Run();
		void OnKeyIn(int keycode);
		void Goto(int viewId);						//Activate a view
		void Prev();
		void Next();
		void Render();								//view contents
		void Output();								//to screen
	private:
		YB_ViewFactory					viewFactory;
		YB_ViewBasis*					currentView;
		stack<YB_ViewBasis*>			viewStack;
		vector<char*>					viewGrid;
		//map<int, YB_ViewBasis>		viewCollection;
	};

}
#endif // YB_Window_H