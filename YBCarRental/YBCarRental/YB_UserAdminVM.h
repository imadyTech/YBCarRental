#define _HAS_STD_BYTE 0

#pragma once
#include <YB_UserManager.h>
#include <YB_CarManager.h>
#include <YB_RentManager.h>
#include "YB_ManagerFactory.h"
#include "YB_Window.h"
#include "YB_ViewModelBasis.h"
using namespace YBConsoleViews;

class YBConsoleViews::YB_Window;



namespace YBCarRental {
	//120 USER INFO UPDATE (admin feature) - InputView
	class YB_UserAdminVM : public YB_ViewModelBasis<YB_User>
	{
	public:
		YB_UserAdminVM(YBConsoleViews::YB_Window* windowPtr) : YB_ViewModelBasis::YB_ViewModelBasis(windowPtr) {}

		YB_UserManager* userManagerPtr = YB_ManagerFactory::UserMgr;
		YB_RentManager* rentManagerPtr = YB_ManagerFactory::RentMgr;
		YB_CarManager* carManagerPtr = YB_ManagerFactory::CarMgr;


		void					onViewForwarded(YB_DataBasis* fromData)		override
		{
			this->principalObject = dynamic_cast<YB_User*>(fromData);
		};


		void					onSubmit(map<string, string>* valuesMapPtr)				override
		{
			auto* userPtr = this->principalObject;

			try {
				//userPtr->Id				= std::stoi((*valuesMapPtr)["Id"]);
				userPtr->UserName = ((*valuesMapPtr)["UserName"]);
				userPtr->FirstName = ((*valuesMapPtr)["FirstName"]);
				userPtr->FamilyName = ((*valuesMapPtr)["FamilyName"]);
				userPtr->UserRoles = ((*valuesMapPtr)["UserRoles"]);
				userPtr->Balance = std::stod((*valuesMapPtr)["Balance"]);
			}
			catch (exception e)
			{
				windowPtr->PopPrompt("Some issues in your input. Please check again.", nullptr);
			}
			try {
				if (userManagerPtr->UpdateUser(userPtr)) {
					windowPtr->PopPrompt("The user info was successfully updated.", ADMIN_MAIN_VIEW.c_str());
				}
				else
				{
					windowPtr->PopPrompt("The user info update was NOT successful.", ADMIN_MAIN_VIEW.c_str());
				}
			}
			catch (exception e)
			{
				windowPtr->PopPrompt("Something goes wrong. Please check again.", nullptr);
			}
		}
	};

}