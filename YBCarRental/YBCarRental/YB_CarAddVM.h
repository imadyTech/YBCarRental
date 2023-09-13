#define _HAS_STD_BYTE 0

#pragma once
#include <YB_CarManager.h>
#include <YB_UserManager.h>
#include "YB_ManagerFactory.h"
#include "YB_Window.h"
#include "YB_ViewModelBasis.h"
#include "YB_Global_Header.h"

using namespace YBConsoleViews;

class YBConsoleViews::YB_Window;



namespace YBCarRental {
	//113 order details - DetailsView
	class YB_CarAddVM : public YB_ViewModelBasis<YB_Car>
	{
	public:
		YB_CarAddVM(YBConsoleViews::YB_Window* windowPtr) : YB_ViewModelBasis::YB_ViewModelBasis(windowPtr) {}

		YB_UserManager* userManagerPtr = YB_ManagerFactory::UserMgr;
		YB_CarManager* carManagerPtr = YB_ManagerFactory::CarMgr;

		void					onViewForwarded(YB_DataBasis* fromData)		override
		{
			this->principalObject = dynamic_cast<YB_Car*>(fromData);
		};


		string* Get_PropertyValue(string* bindName) override
		{
			//show password in MyProfile is forbidden
			if (*bindName == "UserName") {
				auto username = userManagerPtr->CurrentUser()->UserName;
				return &username;
			}
			if (*bindName == "UserRoles") {
				auto userroles = userManagerPtr->CurrentUser()->UserRoles;
				return &userroles;
			}
			return YB_ViewModelBasis::Get_PropertyValue(bindName);
		}

		void					onSubmit(map<string, string>* valuesMapPtr)				override
		{
			string	Make;
			string	Model;
			int		Year;
			int		Mileage;
			bool	IsAvailable=true;
			int		MinRentPeriod;
			int		MaxRentPeriod;
			double	DayRentPrice;

			if (!(*valuesMapPtr)["Make"].empty())				Make = (*valuesMapPtr)["Make"];
			if (!(*valuesMapPtr)["Model"].empty())				Model = (*valuesMapPtr)["Model"];
			if (!(*valuesMapPtr)["Year"].empty())				Year = std::stoi((*valuesMapPtr)["Year"]);
			if (!(*valuesMapPtr)["Mileage"].empty())			Mileage = std::stoi((*valuesMapPtr)["Mileage"]);
			if (!(*valuesMapPtr)["MinRentPeriod"].empty())		MinRentPeriod =  std::stoi((*valuesMapPtr)["MinRentPeriod"]);
			if (!(*valuesMapPtr)["MaxRentPeriod"].empty())		MaxRentPeriod =  std::stoi((*valuesMapPtr)["MaxRentPeriod"]);
			if (!(*valuesMapPtr)["DayRentPrice"].empty())		DayRentPrice =  std::stod((*valuesMapPtr)["DayRentPrice"]);

			YB_Car* car = new YB_Car();
			car->Make				= Make;
			car-> Model				= Model;
			car->Year				= Year;
			car->Mileage			= Mileage;
			car->IsAvailable		= IsAvailable;
			car->MinRentPeriod		= MinRentPeriod;
			car->MaxRentPeriod		= MaxRentPeriod;
			car->DayRentPrice		= DayRentPrice;

			bool result = carManagerPtr->AddCar(car);
			if (result) {
				windowPtr->PopPrompt("The car has been successfully added!", YBConsoleViews::ADMIN_MAIN_VIEW.c_str());
			}
			else
			{
				windowPtr->PopPrompt("There is some issue to add your car information.", nullptr);
			}
		}
	};

}

