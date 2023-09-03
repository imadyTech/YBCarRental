#pragma once
#include "YB_ViewModelBasis.h"
#include <YB_UserManager.h>
#include "YB_Window.h"
using namespace YBConsoleViews;

class YBConsoleViews::YB_Window;



namespace YBCarRental {
	class YB_UserLoginVM : public YB_ViewModelBasis<YB_User>
	{
	public:
		YB_UserLoginVM(YB_UserManager* managerPtr) {
			dataManagerPtr = managerPtr;
		};

		YB_UserManager* dataManagerPtr = {};

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

			bool loginResult = dataManagerPtr->UserLogin(uName, uPsd);
			if (loginResult)
				windowPtr->Goto("MainMenuView");			//Todo: this shall be view.GotoView
		};

		//string* Get_PropertyValue(string* bindNamePtr)										override {};

		//map<string, string>* Get_PropertyValues(string* bindNamePtr)						{
		//	return this->YB_VMBasis<YB_User>::Get_PropertyValue(bindNamePtr);
		//};
		//void					Set_PropertyValue(string* bindNamePtr, string* valuePtr)	override {};
		//void					Set_PropertyValues(map<string, string>* values)				override {};
	};


	class YB_UserRegisterVM : public YB_ViewModelBasis<YB_User>
	{
	public:
		YB_UserRegisterVM(YB_UserManager* managerPtr) {
			this->dataManagerPtr = managerPtr;
		};

		YB_UserManager* dataManagerPtr;
		//string* Get_PropertyValue(string* bindNamePtr)										override {};

		//map<string, string>* Get_PropertyValues(string* bindNamePtr)						{
		//	return this->YB_VMBasis<YB_User>::Get_PropertyValue(bindNamePtr);
		//};
		//void					Set_PropertyValue(string* bindNamePtr, string* valuePtr)	override {};
		//void					Set_PropertyValues(map<string, string>* values)				override {};
	};


	//class YB_UserListVM : public YB_ViewModelBasis<YB_User>
	//{
	//public:
	//	//YB_UserListVM(YB_ManagerBasis<YB_User>* manager) {
	//	//	dataManager = manager;
	//	//}

	//};


	//class YB_CarVM : public YB_ViewModelBasis<YB_Car>
	//{

	//};


	//class YB_RentVM : public YB_ViewModelBasis<YB_Rent>
	//{

	//};
}

