// YBCarRent.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "YB_PersistorBasis.h"
#include "YB_User.h"
#include "YB_UserPersistor.h"
#include "YB_Errors.h"
#include "YB_Window.h"

using namespace YBCarRental;
using namespace YBConsoleViews;

int main()
{
	//If you see this message then congratulation! Likely the build is passed.
	std::cout << "Hello Yoobee-Car-Rental!\n";

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

	YB_PersistorBasis<YB_User> persistor = YB_PersistorBasis<YB_User>("E:/YB800ProSE/YBCarRental/YBCarRental/YBCar_Native_Testing/UserRepo.txt");
	YB_User* userPtr = persistor.Get("fshen");

	cout << userPtr->FirstName << " " << userPtr->FamilyName;

	//initialization
	//managers
		//persistors
	//load viewitems info
		//viewitem instantiation
		//YB_Windows
	YB_Window window = YB_Window();

	//


	//welcome screen
	//try/catch wrapping
		//get key inputs
		//YB_Windows update / response to key input
		//viewitem update viewmodel
		//Managers logic updates driven by viewmodel
		//Persistence
	//Loop

}
