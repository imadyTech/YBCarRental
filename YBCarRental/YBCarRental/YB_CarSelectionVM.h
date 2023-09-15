#pragma once
#include "YB_ViewModelBasis.h"
#include <YB_UserManager.h>
#include <YB_CarManager.h>
#include <YB_RentManager.h>
#include "YB_Window.h"
#include "YB_ManagerFactory.h"
using namespace YBConsoleViews;

class YBConsoleViews::YB_Window;



namespace YBCarRental {


	//109 CarSelection - ListView
	class YB_CarSelectionVM : public YB_ViewModelBasis<YB_Car>
	{
	public:
		YB_CarSelectionVM(YB_CarManager* managerPtr, YBConsoleViews::YB_Window* windowPtr) {
			dataManagerPtr = managerPtr;
			this->windowPtr = windowPtr;
		}
	};
}

