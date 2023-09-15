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

	//108 My orders - ListView
	class YB_MyOrdersVM : public YB_ViewModelBasis<YB_Rent>
	{
	public:
		YB_MyOrdersVM(YB_RentManager* managerPtr, YBConsoleViews::YB_Window* windowPtr) {
			dataManagerPtr = managerPtr;
			this->windowPtr = windowPtr;
		}


	};
}

