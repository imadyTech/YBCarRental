#pragma once
#include "YB_ViewModelBasis.h"
#include <YB_UserManager.h>
#include <YB_CarManager.h>
#include <YB_RentManager.h>
#include "YB_Window.h"
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
			this->principalObject = dataManagerPtr->CurrentUser();

			if (loginResult && !dataManagerPtr->IsAdmin())
				windowPtr->Goto("UserMenu");			//Todo: this shall be view.GotoView
			else if(loginResult && dataManagerPtr->IsAdmin())
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

		YB_UserManager* dataManagerPtr;

		void					onInit()												override
		{

		}
		//string* Get_PropertyValue(string* bindNamePtr)										override {};

		//map<string, string>* Get_PropertyValues(string* bindNamePtr)						{
		//	return this->YB_VMBasis<YB_User>::Get_PropertyValue(bindNamePtr);
		//};
		//void					Set_PropertyValue(string* bindNamePtr, string* valuePtr)	override {};
		//void					Set_PropertyValues(map<string, string>* values)				override {};
	};

	//105 UserMenu
	class YB_UserMenuVM : public YB_ViewModelBasis<YB_User>
	{
	public:
		YB_UserMenuVM(YB_UserManager* managerPtr, YBConsoleViews::YB_Window* windowPtr) {
			dataManagerPtr = managerPtr;
			this->windowPtr = windowPtr;
		}
		YB_UserManager* dataManagerPtr;

		void					onViewForwarded(YB_DataSource_Interface* from)			override 
		{
			this->principalObject = dataManagerPtr->CurrentUser();

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
		YB_UserManager* dataManagerPtr;

		void					onViewForwarded(YB_DataSource_Interface* from)			override 
		{
			this->principalObject = dataManagerPtr->CurrentUser();

		};
	};

	//109 CarSelection ListView
	class CarSelectionView : public YB_ViewModelBasis<YB_Car>
	{
	public:
		CarSelectionView(YB_CarManager* managerPtr, YBConsoleViews::YB_Window* windowPtr) {
			dataManagerPtr = managerPtr;
			this->windowPtr = windowPtr;
		}
		YB_CarManager* dataManagerPtr;

		string*					Get_PropertyValue(string* bindName)						override
		{
			//auto carList = dataManagerPtr->get
			return nullptr;
		};
	};


	//class YB_CarVM : public YB_ViewModelBasis<YB_Car>
	//{

	//};


	//class YB_RentVM : public YB_ViewModelBasis<YB_Rent>
	//{

	//};
}

