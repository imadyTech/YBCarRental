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


	//116 YB_UserAdminListVM - ListView
	class YB_UserAdminListVM : public YB_ViewModelBasis<YB_User>
	{
	public:
		YB_UserAdminListVM(YBConsoleViews::YB_Window* windowPtr) {
			this->dataManagerPtr = YB_ManagerFactory::UserMgr;
		}

		YB_User* carryForwardedUser;

		void					onViewForwarded(YB_DataBasis* fromData)		override
		{
			carryForwardedUser = dynamic_cast<YB_User*>(fromData);
		};

		//DO NOT carryForward current principalObject, this confuse with the current user (Admin) of the current view
		//void					onSubmit(map<string, string>* valuesMapPtr)				override
		//{
		//	
		//	int selectedUserId = -1;
		//	if (!(*valuesMapPtr)["dataId"].empty())
		//		selectedUserId = std::stoi((*valuesMapPtr)["dataId"]);
		//	this->principalObject = dynamic_cast<YB_UserManager*>(dataManagerPtr)->GetUser(selectedUserId);
		//		
		//}
	};
}

