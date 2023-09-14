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
	//119 Admin the order (Admin feature )- InputView
	class YB_OrderAdminVM : public YB_ViewModelBasis<YB_Rent>
	{
	public:
		YB_OrderAdminVM(YBConsoleViews::YB_Window* windowPtr) : YB_ViewModelBasis::YB_ViewModelBasis(windowPtr) {}

		YB_UserManager* userManagerPtr = YB_ManagerFactory::UserMgr;
		YB_RentManager* rentManagerPtr = YB_ManagerFactory::RentMgr;
		YB_CarManager* carManagerPtr = YB_ManagerFactory::CarMgr;


		void					onViewForwarded(YB_DataBasis* fromData)		override
		{
			this->principalObject = dynamic_cast<YB_Rent*>(fromData);
		};


		string* Get_PropertyValue(string* bindName) override
		{
			string* value = new string();
			if (*bindName == "UserName") {
				*value = userManagerPtr->CurrentUser()->UserName;
				return value;
			}
			if (*bindName == "UserRoles") {
				*value = (userManagerPtr->CurrentUser()->UserRoles);
				return value;
			}
			if (*bindName == "CarInfo") {
				auto* car = carManagerPtr->GetCar(principalObject->CarId);
				*value = car->Make + " " + car->Model + " " + to_string(car->Year);
				return value;
			}
			if (*bindName == "CustomerName") {
				*value = userManagerPtr->CurrentUser()->FirstName + " " + userManagerPtr->CurrentUser()->FamilyName;
				return value;
			}
			if (*bindName == "OrderCost") {
				auto* car = carManagerPtr->GetCar(principalObject->CarId);
				*value = to_string(principalObject->RentDays * car->DayRentPrice);
				return value;
			}
			return YB_ViewModelBasis::Get_PropertyValue(bindName);
		}


		void					onSubmit(map<string, string>* valuesMapPtr)				override
		{
			string reviewType = (*valuesMapPtr)[SUBMIT_BINDKEY_BUTTONCONTENT];
			int orderId = std::stoi((*valuesMapPtr)["Id"]);
			if (reviewType == "APPROVE") {
				rentManagerPtr->ApproveOrder(orderId);
				windowPtr->PopPrompt("You have approved the order!", YBConsoleViews::ADMIN_MAIN_VIEW.c_str());
			};
			if (reviewType == "REJECT") {
				rentManagerPtr->RejectOrder(orderId);
				windowPtr->PopPrompt("You have rejected the order.", nullptr);
			};
		}
	};

}