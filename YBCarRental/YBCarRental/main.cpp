// YBCarRent.cpp : This file contains the 'main' function. Program execution begins and ends there.


// This pre-compilation code is to solve the error issue of C2872
// See to https://developercommunity.visualstudio.com/t/error-c2872-byte-ambiguous-symbol/93889
#define _HAS_STD_BYTE 0
// --------------------------------------------------------------

#include <iostream>
#include <filesystem>
#include "YB_UserManager.h"
#include "YB_CarManager.h"
#include "YB_RentManager.h"
#include "YB_Errors.h"
#include "YB_Window.h"
#include "YB_CarRental_LogicFactory.h"

using namespace YBCarRental;
using namespace YBConsoleViews;

int main()
{
	std::filesystem::path currentDir = std::filesystem::current_path();

	YB_UserManager* userMgr		= new YB_UserManager(currentDir.string() + "\\UserRepo.txt");
	userMgr->LoadAll();
	YB_CarManager*	carMgr		= new YB_CarManager	(currentDir.string() + "\\CarRepo.txt");
	carMgr->LoadAll();
	YB_RentManager* rentMgr		= new YB_RentManager(currentDir.string() + "\\RentRepo.txt");
	rentMgr->LoadAll();

	YB_Window windowPtr = YB_Window();

	YB_UserLoginVM* userVM = new YB_UserLoginVM(userMgr);
	userVM->windowPtr = &windowPtr;
	YB_UserRegisterVM* regVM = new YB_UserRegisterVM(userMgr);
	regVM->windowPtr = &windowPtr;

	YB_CarRental_LogicFactory* logicFactory = new YB_CarRental_LogicFactory();
	string userVMName = "YB_UserLoginVM";
	logicFactory->RegisterDataSource(&userVMName, userVM);
	string regVMName = "YB_UserRegisterVM";
	logicFactory->RegisterDataSource(&regVMName, regVM);
	string userMenuVMName = "YB_UserMenuVM";
	logicFactory->RegisterDataSource(&userMenuVMName, new YB_UserMenuVM(userMgr));
	



	windowPtr.ConfigLogicFactory(logicFactory);

	windowPtr.InitViewFactory(currentDir.string() + "\\ViewRepo.txt");
	windowPtr.Init();
	windowPtr.Run();

	cout << "The application quit." << endl;
	//try/catch wrapping
		//get key inputs
		//YB_Windows update / response to key input
		//viewitem update viewmodel
		//Managers logic updates driven by viewmodel
		//Persistence
	//Loop
	//while (true)
	//{
	//	window.OnKeyIn();
	//	window.Render();
	//}

	////Testing the custom YB Errors
	//try {
	//	throw YB_RepositoryError();
	//}
	//catch (const std::exception& e) {
	//	std::cerr << "Caught YB customed exception: " << e.what() << std::endl;
	//}

	//Testing the persistors and how C++ template class and method works.
	//YB_User user = YB_User();       //OK
	//YB_PersistorBasis<YB_DataBasis> userPersistor = YB_PersistorBasis<YB_DataBasis>(); //Not tested
	//YB_PersistorBasis<YB_User> userPersistor = YB_PersistorBasis<YB_User>("This is where the data stored.");  //OK
	//YBCarRental::YB_UserPersistor userPersistor = YBCarRental::YB_UserPersistor("This is where the user data stored."); //OK
	//cout << userPersistor.repositoryURL << endl;

	//YBCarRental::YB_UserPersistor userPersistor = YBCarRental::YB_UserPersistor("E:\\YB800ProSE\\YBCarRental\\YBCarRental\\x64\\Debug\\UserDatabase.txt"); //OK
	//cout << userPersistor.repositoryURL << endl;

	////OK
	//YB_User user = YB_User();
	//user.FirstName = "Frank";
	//user.FamilyName = "Shen";
	//user.Id = 15;
	//user.Password = "666666";
	//user.UserName = "fshen";
	//user.LoginStatus = false;
	//user.UserRoles = "user:admin";
	//user.Balance = 10000;
	////OK

	//ofstream outputfile("UserRepo.txt");
	//if (!outputfile.is_open())
	//{
	//	cerr << "The file is not opened!" << endl;
	//}
	//user.Serialize(&outputfile);

	//YB_Repository repo = YB_Repository("UserRepo.txt");
	//cout << repo.isReady;

	//YB_PersistorBasis<YB_User> persistor = YB_PersistorBasis<YB_User>("E:/YB800ProSE/YBCarRental/YBCarRental/YBCar_Native_Testing/UserRepo.txt");
	//persistor.GetAll();
	//cout << "END";

	//YB_PersistorBasis<YB_User> persistor = YB_PersistorBasis<YB_User>("E:/YB800ProSE/YBCarRental/YBCarRental/YBCar_Native_Testing/UserRepo.txt");
	//YB_User* userPtr = persistor.Get("fshen");
	//cout << userPtr->FirstName << " " << userPtr->FamilyName;

}
