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
	/// 102 - LoginView
	class YB_UserLoginVM : public YB_ViewModelBasis<YB_User>
	{
	public:
		YB_UserLoginVM(YB_UserManager* managerPtr, YBConsoleViews::YB_Window* windowPtr) {
			dataManagerPtr = managerPtr;
			this->windowPtr = windowPtr;
		};

		void					onSubmit(map<string, string>* valuesMapPtr)				override
		{
			string uName = "";
			string uPsd = "";
			const auto& nItr = valuesMapPtr->find(const_cast<char*>("UserName"));
			if (nItr != valuesMapPtr->end())
				uName = nItr->second;
			const auto& pItr = valuesMapPtr->find(const_cast<char*>("Password"));
			if (pItr != valuesMapPtr->end())
				uPsd = pItr->second;

			auto manager = dynamic_cast<YB_UserManager*>(dataManagerPtr);

			bool loginResult = manager->UserLogin(uName, uPsd);
			this->principalObject = manager->CurrentUser();

			if (loginResult && !manager->IsAdmin())
				windowPtr->Goto(USER_MAIN_VIEW);			//Todo: this shall be view.GotoView
			else if (loginResult && manager->IsAdmin())
				windowPtr->Goto(ADMIN_MAIN_VIEW);
		};
	};
}

