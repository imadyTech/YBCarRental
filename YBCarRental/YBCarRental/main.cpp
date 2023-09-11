// YBCarRent.cpp : This file contains the 'main' function. Program execution begins and ends there.


// This pre-compilation code is to solve the error issue of C2872
// See to https://developercommunity.visualstudio.com/t/error-c2872-byte-ambiguous-symbol/93889
#define _HAS_STD_BYTE 0
// --------------------------------------------------------------

#include <iostream>
#include <filesystem>
#include "YB_Errors.h"
#include "YB_Window.h"
#include "YB_CarRental_LogicFactory.h"
#include "YB_ManagerFactory.h"


using namespace YBCarRental;
using namespace YBConsoleViews;


int main()
{
	const std::string		INIT_VIEW = "WelcomeView";
	const std::string		EXIT_VIEW = "ByeByeView";
	std::filesystem::path	currentDir = std::filesystem::current_path();

	YB_Window				windowPtr = YB_Window();
	YB_ManagerFactory		managerFactory = YB_ManagerFactory();

	YB_CarRental_LogicFactory* logicFactory = new YB_CarRental_LogicFactory();
	logicFactory->RegisterDataSource("YB_UserLoginVM", new YB_UserLoginVM(YB_ManagerFactory::UserMgr, &windowPtr));
	logicFactory->RegisterDataSource("YB_UserRegisterVM", new YB_UserRegisterVM(YB_ManagerFactory::UserMgr, &windowPtr));
	logicFactory->RegisterDataSource("YB_UserMenuVM", new YB_UserMenuVM(YB_ManagerFactory::UserMgr, &windowPtr));
	logicFactory->RegisterDataSource("YB_AdminMenuVM", new YB_AdminMenuVM(YB_ManagerFactory::UserMgr, &windowPtr));
	logicFactory->RegisterDataSource("YB_CarSelectionVM", new YB_CarSelectionVM(YB_ManagerFactory::CarMgr, &windowPtr));
	logicFactory->RegisterDataSource("YB_CarRentVM", new YB_CarRentVM(YB_ManagerFactory::CarMgr, &windowPtr));

	windowPtr.ConfigLogicFactory(logicFactory);
	windowPtr.InitViewFactory(currentDir.string() + "\\ViewRepo.txt");
	windowPtr.initViewName = INIT_VIEW;
	windowPtr.exitViewName = EXIT_VIEW;
	windowPtr.Init();
	windowPtr.Run();

	cout << "The application quit." << endl;
}
