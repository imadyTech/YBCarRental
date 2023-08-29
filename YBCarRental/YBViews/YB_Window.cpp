#include "YB_Window.h"


namespace YBConsoleViews
{

	void YB_Window::InitViewFactory(string viewRepo)
	{
		viewFactory = YB_ViewFactory(viewRepo);
	}

	void YB_Window::Init()
	{
		currentView = viewFactory.GetView(1);					//Load and show Welcome view
	}

	void YB_Window::Run()
	{
		int keycode;
		while (true) {
			if (_kbhit()) {
				keycode = _getch();
				if (keycode == 120) {							//F9, escape the application.
					break;
				}
				else
					OnKeyIn(keycode);
			}
			Render();
			Output();
			Sleep(300);
		}
	}

	void YB_Window::OnKeyIn(int key)
	{
		if (key == 9 || key == 10 || key == 8 ||					//tab/return/backspace
			(key >= 65 && key <= 90) ||							//Alphabet(Upper/Lower) and numbers
			(key >= 48 && key <= 57) ||
			(key >= 97 && key <= 122))
		{
			currentView->OnKey(&key);
		}
	}

	void YB_Window::Goto(int viewId)
	{
		currentView = viewFactory.GetView(viewId);
	}

	void YB_Window::Prev()
	{
	}

	void YB_Window::Next()
	{
	}


	void YB_Window::Render()
	{
		if (currentView)
			this->viewGrid = currentView->Render();
	}
	void YB_Window::Output()
	{
		system("cls");
		for (const char* strptr : this->viewGrid) {
			std::cout << strptr << std::endl;
		}
	}

}