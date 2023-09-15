#pragma once
#include "YB_ViewModelBasis.h"
#include <YB_UserManager.h>
#include "YB_Window.h"
#include "YB_ManagerFactory.h"
using namespace YBConsoleViews;

class YBConsoleViews::YB_Window;


namespace YBCarRental {

	//103 - RegisterView
	class YB_LogOutVM : public YB_ViewModelBasis<YB_User>
	{
	public:
		YB_LogOutVM(YBConsoleViews::YB_Window* windowPtr) : YB_ViewModelBasis::YB_ViewModelBasis(windowPtr) {}

		YB_UserManager* userManagerPtr = YB_ManagerFactory::UserMgr;


		string* Get_PropertyValue(string* bindName) override
		{
			string* value = new string();
			if (*bindName == "SeeYou") {
				*value = "See ya, "+userManagerPtr->CurrentUser()->FirstName;
				return value;
			}
			return YB_ViewModelBasis::Get_PropertyValue(bindName);
		}


		void					onSubmit(map<string, string>* valuesMapPtr)				override
		{
			this->userManagerPtr->UserLogout();
		}
	};


}

