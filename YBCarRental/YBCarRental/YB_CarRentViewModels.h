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

	//111 YB_CarListVM - ListView
	class YB_CarListVM : public YB_ViewModelBasis<YB_Car>
	{
	public:
		YB_CarListVM(YBConsoleViews::YB_Window* windowPtr) {
			this->dataManagerPtr = YB_ManagerFactory::CarMgr;
		}

		YB_User* carryForwardedUser;
		void					onViewForwarded(YB_DataBasis* fromData)		override
		{
			carryForwardedUser = dynamic_cast<YB_User*>(fromData);
		};
	};	
	
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
	
	//118 YB_CarDeleteVm- ListView
	class YB_CarDeleteVm : public YB_ViewModelBasis<YB_Car>
	{
	public:
		YB_CarDeleteVm (YBConsoleViews::YB_Window* windowPtr) {
			this->dataManagerPtr = YB_ManagerFactory::CarMgr;
		}

		void					onViewForwarded(YB_DataBasis* fromData)		override
		{
			this->principalObject = dynamic_cast<YB_Car*>(fromData);
		};

		void					onSubmit(map<string, string>* valuesMapPtr)				override
		{
			bool deleteResult = dynamic_cast<YB_CarManager*>( this->dataManagerPtr )->DeleteCar(this->principalObject);

			//if (deleteResult)
			//	windowPtr->Goto("UserMenu");
			//else if (deleteResult)
			//	windowPtr->Goto("AdminMenu");
		};

	};



	//class YB_CarVM : public YB_ViewModelBasis<YB_Car>
	//{

	//};


	//class YB_RentVM : public YB_ViewModelBasis<YB_Rent>
	//{

	//};
}

