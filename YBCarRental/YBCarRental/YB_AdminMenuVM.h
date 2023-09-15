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

	//106 AdminMenu
	class YB_AdminMenuVM : public YB_ViewModelBasis<YB_User>
	{
	public:
		YB_AdminMenuVM(YB_UserManager* managerPtr, YBConsoleViews::YB_Window* windowPtr) {
			dataManagerPtr = managerPtr;
			this->windowPtr = windowPtr;
		}

		void					onViewForwarded(YB_DataBasis* fromData)		override
		{
			auto manager = dynamic_cast<YB_UserManager*>(dataManagerPtr);
			this->principalObject = manager->CurrentUser();
		};
	};
}

