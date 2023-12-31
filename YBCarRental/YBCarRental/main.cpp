// YBCarRent.cpp : This file contains the 'main' function. Program execution begins and ends there.


// This pre-compilation code is to solve the error issue of C2872
// See to https://developercommunity.visualstudio.com/t/error-c2872-byte-ambiguous-symbol/93889
#define _HAS_STD_BYTE 0
// --------------------------------------------------------------

#include <iostream>
#include <filesystem>
#include "YB_Errors.h"
#include "YB_Window.h"
#include "YB_ManagerFactory.h"
#include "YB_CarRental_LogicFactory.h"
//Include ViewModels
#include "YB_UserMenuVM.h"
#include "YB_AdminMenuVM.h"
#include "YB_CarSelectionVM.h"
#include "YB_CarRentVM.h"
#include "YB_MyOrdersVM.h"
#include "YB_CarAddVM.h"
#include "YB_CarManageVM.h"
#include "YB_CarListVM.h"
#include "YB_CarDeleteListVM.h"
#include "YB_CarDeleteVm.h"
#include "YB_OrderManageVM.h"
#include "YB_UserAdminListVM.h"
#include "YB_MyProfileVM.h"
#include "YB_OrderDetailsVM.h"
#include "YB_OrderAdminVM.h"
#include "YB_UserAdminVM.h"
#include "YB_UserRegisterVM.h"
#include "YB_UserLoginVM.h"
#include "YB_LogOutVM.h"
//Include ViewModels


using namespace YBConsoleViews;

using namespace YBCarRental;

int main()
{
	//const std::string		INIT_VIEW = "LoginView";
	//const std::string		EXIT_VIEW = "ByeByeView";
	std::filesystem::path	currentDir = std::filesystem::current_path();

	YBConsoleViews::YB_Window*				windowPtr =new YBConsoleViews::YB_Window();
	YB_ManagerFactory		managerFactory = YB_ManagerFactory();

	//Register viewModels to dataservice factory
	YB_CarRental_LogicFactory* logicFactory = new YB_CarRental_LogicFactory();
	logicFactory->RegisterDataSource("YB_UserLoginVM",		new YB_UserLoginVM(YB_ManagerFactory::UserMgr, windowPtr));
	logicFactory->RegisterDataSource("YB_UserRegisterVM",	new YB_UserRegisterVM(windowPtr));
	logicFactory->RegisterDataSource("YB_UserMenuVM",		new YB_UserMenuVM(YB_ManagerFactory::UserMgr, windowPtr));
	logicFactory->RegisterDataSource("YB_AdminMenuVM",		new YB_AdminMenuVM(YB_ManagerFactory::UserMgr, windowPtr));
	logicFactory->RegisterDataSource("YB_CarSelectionVM",	new YB_CarSelectionVM(YB_ManagerFactory::CarMgr, windowPtr));
	logicFactory->RegisterDataSource("YB_CarRentVM",		new YB_CarRentVM(YB_ManagerFactory::CarMgr, windowPtr));
	logicFactory->RegisterDataSource("YB_MyOrdersVM",		new YB_MyOrdersVM(YB_ManagerFactory::RentMgr, windowPtr));
	logicFactory->RegisterDataSource("YB_OrderDetailsVM",	new YB_OrderDetailsVM(windowPtr));
	logicFactory->RegisterDataSource("YB_MyProfileVM",		new YB_MyProfileVM(windowPtr));
	logicFactory->RegisterDataSource("YB_CarAddVM",			new YB_CarAddVM(windowPtr));//admin
	logicFactory->RegisterDataSource("YB_CarListVM",		new YB_CarListVM(windowPtr));//admin listing
	logicFactory->RegisterDataSource("YB_CarManageVM",		new YB_CarManageVM(windowPtr));//admin
	logicFactory->RegisterDataSource("YB_CarDeleteListVM",	new YB_CarDeleteListVM(windowPtr));//admin
	logicFactory->RegisterDataSource("YB_CarDeleteVm",		new YB_CarDeleteVm(windowPtr));//admin
	logicFactory->RegisterDataSource("YB_OrderManageVM",	new YB_OrderManageVM(windowPtr));//admin - list all orders
	logicFactory->RegisterDataSource("YB_OrderAdminVM",		new YB_OrderAdminVM(windowPtr));//admin - approve or reject
	logicFactory->RegisterDataSource("YB_UserAdminListVM",	new YB_UserAdminListVM(windowPtr));//admin
	logicFactory->RegisterDataSource("YB_UserAdminVM",		new YB_UserAdminVM(windowPtr));//admin
	logicFactory->RegisterDataSource("YB_LogOutVM",			new YB_LogOutVM(windowPtr));//admin

	windowPtr->ConfigLogicFactory(logicFactory);
	windowPtr->InitViewFactory(currentDir.string() + "\\ViewRepo.txt");
	windowPtr->initViewName = INIT_VIEW;
	windowPtr->exitViewName = EXIT_VIEW;
	windowPtr->Init();
	windowPtr->Run();

	cout << "The application quit." << endl;
}
