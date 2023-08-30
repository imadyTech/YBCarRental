#ifndef YB_Window_H
#define YB_Window_H
#include <stack>
#include <string>
#include <conio.h>
//#include <iostream>
//#include <cstdlib>
#include <windows.h>
//#include "YB_ViewBasis.h"
#include "YB_ViewFactory.h"
#include "YB_LogicFactory.h"
#include <functional>
//#include "YB_ViewItemFactory.h"

using namespace std;

namespace YBConsoleViews
{
	class YB_ViewBasis;						//Forward declaration in C++
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

		void							ConfigLogicFactory(YB_LogicFactory* logic);

		void							Init();
		void							Run();
		void							OnKeyIn(int keycode);
		void							Goto(int viewId);						//Activate a view
		void							Prev();
		void							Next();
		void							Render();								//view contents
		void							Output();								//to screen

	private:
		YB_ViewFactory*					viewFactory = new YB_ViewFactory();
		YB_LogicFactory*				logicFactory;
		YB_ViewBasis*					currentView;
		stack<YB_ViewBasis*>			viewStack;
		vector<char*>					viewGrid;
	};

}
#endif // YB_Window_H