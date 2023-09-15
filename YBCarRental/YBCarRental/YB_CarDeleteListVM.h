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



	//117 YB_CarDeleteListVM- ListView
	class YB_CarDeleteListVM : public YB_ViewModelBasis<YB_Car>
	{
	public:
		YB_CarDeleteListVM(YBConsoleViews::YB_Window* windowPtr) {
			this->dataManagerPtr = YB_ManagerFactory::CarMgr;
		}

		YB_User* carryForwardedUser;
		void					onViewForwarded(YB_DataBasis* fromData)		override
		{
			carryForwardedUser = dynamic_cast<YB_User*>(fromData);
		};
	};
}

