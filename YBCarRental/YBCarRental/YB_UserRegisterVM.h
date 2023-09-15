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

	//103 - RegisterView
	class YB_UserRegisterVM : public YB_ViewModelBasis<YB_User>
	{
	public:
		YB_UserRegisterVM (YBConsoleViews::YB_Window* windowPtr) : YB_ViewModelBasis::YB_ViewModelBasis(windowPtr) {}
		
		YB_UserManager* userManagerPtr = YB_ManagerFactory::UserMgr;

		void					onViewForwarded(YB_DataBasis* fromData)		override
		{
			//for Register, always starts from an empty user
			YB_User* userPtr = new YB_User();
			userPtr->Balance = 0;
			userPtr->UserRoles = "user";
			userPtr->LoginStatus = false;
			this->principalObject = userPtr;
		}

		void					onSubmit(map<string, string>* valuesMapPtr)				override
		{
			auto* userPtr = this->principalObject;

			try {
				//userPtr->Id				= std::stoi((*valuesMapPtr)["Id"]);
				userPtr->UserName	= ((*valuesMapPtr)["UserName"]);
				userPtr->FirstName	= ((*valuesMapPtr)["FirstName"]);
				userPtr->FamilyName = ((*valuesMapPtr)["FamilyName"]);
				userPtr->Password	= ((*valuesMapPtr)["Password"]);
			}
			catch (exception e)
			{
				windowPtr->PopPrompt("Some issues in your input. Please check again.", nullptr);
			}

			//Input verification
			if (userPtr->UserName.size() > 10 || userPtr->UserName.size() < 3) {
				windowPtr->PopPrompt("UserName length must between 3 and 10 characters.", nullptr);
				return;
			}
			if (userPtr->FirstName.size() > 12 || userPtr->FirstName.size() < 3) {
				windowPtr->PopPrompt("First Name length must between 3 and 12 characters..", nullptr);
				return;
			}
			if (userPtr->FamilyName.size() > 12 || userPtr->FamilyName.size() < 3) {
				windowPtr->PopPrompt("Family Name length must between 3 and 12 characters.", nullptr);
				return;
			}
			if (userPtr->Password.size() > 6 || userPtr->Password.size() < 1) {
				windowPtr->PopPrompt("Must input a password no more than 6 digits or characters.", nullptr);
				return;
			}

			try {
				if (userManagerPtr->UserRegister(*userPtr)) {
					windowPtr->PopPrompt("The new user was successfully registered.", MAIN_VIEW.c_str());
				}
				else
				{
					windowPtr->PopPrompt("The user registration was NOT successful.", MAIN_VIEW.c_str());
				}
			}
			catch (exception e)
			{
				windowPtr->PopPrompt("Something goes wrong. Please check again.", nullptr);
			}
		}
	};


}

