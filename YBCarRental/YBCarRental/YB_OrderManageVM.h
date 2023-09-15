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


	//115 YB_OrderManageVM - ListView
	class YB_OrderManageVM : public YB_ViewModelBasis<YB_Rent>
	{
	public:
		YB_OrderManageVM(YBConsoleViews::YB_Window* windowPtr) {
			this->dataManagerPtr = YB_ManagerFactory::RentMgr;
		}

		YB_User* carryForwardedUser;

		void					onViewForwarded(YB_DataBasis* fromData)		override
		{
			carryForwardedUser = dynamic_cast<YB_User*>(fromData);
		};
	};
}

