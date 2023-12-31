#ifndef YB_Window_H
#define YB_Window_H
#include <stack>
#include <string>
#include <conio.h>
#include <functional>
#include <iostream>
//#include <cstdlib>
#include <windows.h>
//#include "YB_ViewBasis.h"
#include "YB_ViewFactory.h"
#include "YB_LogicFactory.h"

using namespace std;
namespace YBConsoleViews
{
	class YB_ViewBasis;						//Forward declaration in C++
	class YB_Window
	{
	public:
		YB_Window() {};

		void InitViewFactory(string viewRepo);

		string							initViewName="";
		string							exitViewName="";


		void							ConfigLogicFactory(YB_LogicFactory* logic);

		void							Init();
		void							Run();
		void							OnKeyIn(int keycode);
		void							Goto(int viewId);								//Activate a view by id
		void							Goto(const string viewTitle);					//Activate a view by title
		void							Back();
		void							PopPrompt(const char* promptPtr, const char* gotoLink);

	private:
		void							Goto(YB_ViewBasis* viewPtr);					//Activate a view
		void							Output();
		YB_ViewFactory*					viewFactory = new YB_ViewFactory();
		YB_LogicFactory*				logicFactory;
		YB_ViewBasis*					currentView;
		stack<YB_ViewBasis*>			viewStack;
		vector<char*>					viewGrid;										//Rendering grids
	};

}
#endif // YB_Window_H