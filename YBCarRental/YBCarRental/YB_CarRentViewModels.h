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
			string uName	= "";
			string uPsd		= "";
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
				windowPtr->Goto("UserMenu");			//Todo: this shall be view.GotoView
			else if(loginResult && manager->IsAdmin())
				windowPtr->Goto("AdminMenu");
		};
	};

	//103 - RegisterView
	class YB_UserRegisterVM : public YB_ViewModelBasis<YB_User>
	{
	public:
		YB_UserRegisterVM(YB_UserManager* managerPtr, YBConsoleViews::YB_Window* windowPtr) {
			this->windowPtr = windowPtr;
			this->dataManagerPtr = managerPtr;
		};
	};

	//105 UserMenu
	class YB_UserMenuVM : public YB_ViewModelBasis<YB_User>
	{
	public:
		YB_UserMenuVM(YB_UserManager* managerPtr, YBConsoleViews::YB_Window* windowPtr) {
			dataManagerPtr = managerPtr;
			this->windowPtr = windowPtr;
		}

		void					onViewForwarded(YB_DataBasis* fromData)		override
		{
			auto manager = dynamic_cast<YB_UserManager*>(dataManagerPtr);

			this->principalObject = manager->CurrentUser();

		};
	};	
	
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

	//108 My orders - ListView
	class YB_MyOrdersVM : public YB_ViewModelBasis<YB_Rent>
	{
	public:
		YB_MyOrdersVM (YB_RentManager* managerPtr, YBConsoleViews::YB_Window* windowPtr) {
			dataManagerPtr = managerPtr;
			this->windowPtr = windowPtr;
		}


	};
		
	//109 CarSelection - ListView
	class YB_CarSelectionVM : public YB_ViewModelBasis<YB_Car>
	{
	public:
		YB_CarSelectionVM(YB_CarManager* managerPtr, YBConsoleViews::YB_Window* windowPtr) {
			dataManagerPtr = managerPtr;
			this->windowPtr = windowPtr;
		}
	};




	//class YB_CarVM : public YB_ViewModelBasis<YB_Car>
	//{

	//};


	//class YB_RentVM : public YB_ViewModelBasis<YB_Rent>
	//{

	//};
}

