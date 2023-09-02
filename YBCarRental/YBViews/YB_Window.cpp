#include "YB_Window.h"


namespace YBConsoleViews
{
	void YB_Window::ConfigLogicFactory(YB_LogicFactory* businessLogic)
	{
		this->logicFactory = businessLogic;
	}


	void YB_Window::InitViewFactory(string viewRepo)
	{
		viewFactory = new YB_ViewFactory(viewRepo);
		viewFactory->logicFactory = this->logicFactory;
		viewFactory->LoadAllViews();
	}

	void YB_Window::Init()
	{
		currentView = (*viewFactory).GetView("LoginView");					//Load and show Welcome view
		currentView->ViewReturnCallback = [this]() { Goto(100); };			//*******demo how to use callback
		//currentView = (*viewFactory).GetView(???);						//Byebye view
		//currentView->ViewReturnCallback = [this]() { Todo _someCode_exit; };	//quit

		currentView->Init();											
	}

	void YB_Window::Run()
	{
		int keycode;
		while (true) {
			if (_kbhit()) {
				keycode = _getch();
				if (keycode == 224 || keycode == 0)							//For arrow and Functions keys, must read twice and take the latter value
					keycode = _getch();		
				if (keycode == 120) {										//F9, escape the application.
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

	/// <summary>
	/// Cascaded keycode process with the order: window -> derivedView -> viewBasis -> derivedItem -> itemBasis
	/// </summary>
	/// <param name="key"></param>
	void YB_Window::OnKeyIn(int key)
	{
		if (key  == 120){													//F9, Todo
			Goto("ByeByeView");
		}
		//All keys pass to derived view -> modify derived.Onkey() to implement features.
		if (key == 9 || key == 10 || key == 8	||							//tab/return/backspace
			(key >= 48 && key <= 57)			||							//numbers
			(key >= 65 && key <= 90)			||							//Alphabet(Upper) 
			(key >= 97 && key <= 122)			||							//Alphabet(Lower) 
			(key >= 37 && key <= 40) )										//Lft/Up/Rht/Dw arrow 
		{
			currentView->OnKey(&key);
		}
	}

	void YB_Window::Goto(int viewId)
	{
		currentView = (*viewFactory).GetView(viewId);
		currentView->Init();
	}
	void YB_Window::Goto(const string viewTitle)
	{
		currentView = viewFactory->GetView(viewTitle);
		currentView->Init();
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