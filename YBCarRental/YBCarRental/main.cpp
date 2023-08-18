// YBCarRent.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "YB_PersistorBasis.h"
#include "YB_User.h"
#include "YB_UserPersistor.h"
using namespace YBCarRental;

int main()
{
    std::cout << "Hello Yoobee-Car-Rental!\n";
    //YB_User user = YB_User();       //OK
    //YB_PersistorBasis<YB_DataBasis> userPersistor = YB_PersistorBasis<YB_DataBasis>(); //Not tested
    //YB_PersistorBasis<YB_User> userPersistor = YB_PersistorBasis<YB_User>("This is where the data stored.");  //OK
    YBCarRental::YB_UserPersistor userPersistor =  YBCarRental::YB_UserPersistor("This is where the user data stored."); //OK
    cout << userPersistor.repositoryURL << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
