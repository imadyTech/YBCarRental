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
		viewFactory->windowPtr = this;
		viewFactory->logicFactory = this->logicFactory;
		viewFactory->LoadAllViews();
	}

	void YB_Window::Init()
	{
		Goto(this->initViewName);

		//currentView->ViewReturnCallback = [this]() { Goto(100); };			//*******demo how to use callback
		//currentView = (*viewFactory).GetView(???);							//Byebye view
		//currentView->ViewReturnCallback = [this]() { Todo _someCode_exit; };	//quit
	}

	void YB_Window::Run()
	{
		//==========================Key and processor=============================
		// Ctrl+Q:		Window		Keycode: 17					Quit
		// Esc:			Window		Keycode: 27					View rewind
		// Tab:			View		Keycode: 9					Toggle items
		// Enter:		View		Keycode: 13					Focused item click (select)
		// Backspace:	ViewItem	Keycode: 8					Modify input
		// Num:			ViewItem	Keycode: 48-57				input
		// Alphabete:	ViewItem	Keycode: 65-90, 97-122		input
		// Spacce:		ViewItem	Keycode: 32					input
		// F9:			Window		Keycode: 0+67				NA
		// Delete:		ViewItem	Keycode: 224+83				NA
		// LeftArrow				Keycode: 224+75				NA
		// UpArrow					Keycode: 224+72				NA
		// RightArrow				Keycode: 224+77				NA
		// DownArrow				Keycode: 224+80				NA
		//========================================================================
		int keycode, keycode1;
		while (true) {
			//Phase 1.
			if (!currentView->isInitedFlag)	currentView->Init();
			//Phase 2.
			if (!currentView->isBindedFlag)	currentView->Bind();
			//Phase 3. User input
			if (_kbhit()) {
				keycode = _getch();
				keycode1 = -1;
				//For Arrows and Functions keys, must read twice and take the latter
				if (keycode == 0) {
					keycode1 = _getch();
					continue;											//Functions, Not response
				}
				if (keycode == 224) {
					keycode = _getch() + 256;							//Arrows
				}
				if (keycode1 == -1 && keycode == 17) {					//Ctrl+Q, escape the application.
					this->Goto(this->exitViewName);
					continue;
				}
				if (keycode1 == -1 && keycode == 27) {					//Esc, rewind view.	
					this->Back();
				}
				this->OnKeyIn(keycode);
			}
			//Phase 4. Reverse bind changed viewItems to datasource
			//if (currentView->isUpdatedFlag)	currentView->ReverseBind();
			//Phase 5.
			if (currentView && currentView->isInitedFlag) this->viewGrid = currentView->Render();
			//Phase 6. Output
			this->Output();
			//Phase 7. adjust this parameter if your computer is too fast or slow
			Sleep(100);
		}
	}

	/// <summary>
	/// Cascaded keycode process with the order: window -> derivedView -> viewBasis -> derivedItem -> itemBasis
	/// </summary>
	/// <param name="key"></param>
	void YB_Window::OnKeyIn(int key)
	{
		//All keys pass to derived view -> modify derived.Onkey() to implement features.
		if (key == 9 || key == 13 || key == 8 ||							//tab/return/backspace
			(key >= 48 && key <= 57) ||										//numbers
			(key >= 65 && key <= 90) ||										//Alphabet(Upper) 
			(key >= 97 && key <= 122) ||									//Alphabet(Lower) 
			(key >= 328 && key <= 336))										//Lft/Up/Rht/Dw arrow 
		{
			currentView->OnKey(&key);
		}
	}

	void YB_Window::Goto(YB_ViewBasis* viewPtr)
	{
		if (currentView && !currentView->isKeepStatusFlag)	
			currentView->Exit();

		if (!viewPtr)		viewPtr = viewFactory->GetView(ERROR_VIEW);

		viewPtr->fromViewPtr = currentView;
		currentView = viewPtr;

		this->viewStack.push(currentView);
	}

	void YB_Window::Goto(int viewId)
	{
		this->Goto((*viewFactory).GetView(viewId));
	}

	void YB_Window::Goto(const string viewTitle)
	{
		this->Goto(viewFactory->GetView(viewTitle));
	}

	void YB_Window::Back()
	{
		if (!this->viewStack.empty() && this->viewStack.size()>1) {
			this->currentView->Exit();
			this->viewStack.pop();
			this->currentView = this->viewStack.top();
		}
	}

	void YB_Window::PopPrompt(const char* promptPtr, const char* gotoLink)
	{
		currentView->PopPrompt(promptPtr, gotoLink);
	}

	void YB_Window::Output()
	{
		system("cls");
		for (const char* strptr : this->viewGrid) {
			std::cout << strptr << std::endl;
		}
	}
}