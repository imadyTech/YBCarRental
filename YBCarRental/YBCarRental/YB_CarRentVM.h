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
	//112 rent a car - InputView
	class YB_CarRentVM : public YB_ViewModelBasis<YB_Car>
	{
	public:
		YB_CarRentVM(YB_CarManager* managerPtr, YBConsoleViews::YB_Window* windowPtr) {
			dataManagerPtr = managerPtr;
			this->windowPtr = windowPtr;
		}

		YB_UserManager* userManagerPtr	= YB_ManagerFactory::UserMgr;
		YB_RentManager* rentManagerPtr	= YB_ManagerFactory::RentMgr;
		YB_CarManager* carManagerPtr	= YB_ManagerFactory::CarMgr;


		void					onViewForwarded(YB_DataBasis* fromData)		override
		{
			this->principalObject = dynamic_cast<YB_Car*>(fromData);
		};


		string*					Get_PropertyValue(string* bindName) override
		{
			string* value = new string();
			if (*bindName == "UserName")
			{
				*value = userManagerPtr->CurrentUser()->UserName;
				return value;
			}
			if (*bindName == "Balance") {
				*value = to_string((userManagerPtr->CurrentUser()->Balance));
				return value;
			}
			return YB_ViewModelBasis::Get_PropertyValue(bindName);
		}


		void					onSubmit(map<string, string>* valuesMapPtr)				override
		{
			int* daysToRent = new int(0);
			int* carId = new int(0);

			time_t rawtime;
			struct tm* startDate{};
			localtime_s(startDate, &rawtime);

			string key = "DaysToRent";
			if (!(*valuesMapPtr)[key].empty())
				*daysToRent = std::stoi((*valuesMapPtr)[key]);
			key = "Id";
			if (!(*valuesMapPtr)[key].empty())
				*carId = std::stoi((*valuesMapPtr)[key]);

			YB_Car* car = carManagerPtr->GetCar(*carId);
			YB_Rent* order = new YB_Rent();
			int totalPrice = (car->DayRentPrice) * (*daysToRent);

			if (userManagerPtr->CurrentUser()->Balance >= totalPrice) {
				bool result = rentManagerPtr->PlaceOrder((userManagerPtr->CurrentUser())->Id,
					*carId,
					*startDate,
					*daysToRent);
				//order success, deduct account balance
				if (result)
					userManagerPtr->CurrentUser()->Balance -= totalPrice;
				userManagerPtr->Update(*userManagerPtr->CurrentUser());
			}
			else
			{
				//Todo: prompt insurfficient balance.
			}
		}
	};

}