#define _HAS_STD_BYTE 0

#pragma once
#include <YB_UserManager.h>
#include "YB_ManagerFactory.h"
#include "YB_Window.h"
#include "YB_ViewModelBasis.h"
using namespace YBConsoleViews;

class YBConsoleViews::YB_Window;



namespace YBCarRental {
	//113 order details - DetailsView
	class YB_MyProfileVM : public YB_ViewModelBasis<YB_User>
	{
	public:
		YB_MyProfileVM(YBConsoleViews::YB_Window* windowPtr): YB_ViewModelBasis::YB_ViewModelBasis(windowPtr){}

		YB_UserManager* userManagerPtr = YB_ManagerFactory::UserMgr;

		void					onViewForwarded(YB_DataBasis* fromData)		override
		{
			this->principalObject = dynamic_cast<YB_User*>(fromData);
		};


		string* Get_PropertyValue(string* bindName) override
		{
			//show password in MyProfile is forbidden
			if (*bindName == "Password")	return nullptr;

			return YB_ViewModelBasis::Get_PropertyValue(bindName);
		}
	};

}