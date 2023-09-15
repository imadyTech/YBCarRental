#define _HAS_STD_BYTE 0

#pragma once
#include <YB_CarManager.h>
#include "YB_ManagerFactory.h"
#include "YB_Window.h"
#include "YB_ViewModelBasis.h"
#include "YB_Global_Header.h"

using namespace YBConsoleViews;

class YBConsoleViews::YB_Window;



namespace YBCarRental {
	//114 update or delete car - InputView
	class YB_CarManageVM : public YB_ViewModelBasis<YB_Car>
	{
	public:
		YB_CarManageVM(YBConsoleViews::YB_Window* windowPtr) : YB_ViewModelBasis::YB_ViewModelBasis(windowPtr) {
		this->dataManagerPtr = YB_ManagerFactory::CarMgr;
		}

		YB_CarManager* carManagerPtr = YB_ManagerFactory::CarMgr;



		void					onViewForwarded(YB_DataBasis* fromData)		override
		{
			this->principalObject = dynamic_cast<YB_Car*>(fromData);
		};

		void					onSubmit(map<string, string>* valuesMapPtr)				override
		{
			int		Id;
			string	Make;
			string	Model;
			int		Year;
			int		Mileage;
			bool	IsAvailable = true;
			int		MinRentPeriod;
			int		MaxRentPeriod;
			double	DayRentPrice;

			if (!(*valuesMapPtr)["Id"].empty())					Id = std::stoi((*valuesMapPtr)["Id"]);
			if (!(*valuesMapPtr)["Make"].empty())				Make = (*valuesMapPtr)["Make"];
			if (!(*valuesMapPtr)["Model"].empty())				Model = (*valuesMapPtr)["Model"];
			if (!(*valuesMapPtr)["Year"].empty())				Year = std::stoi((*valuesMapPtr)["Year"]);
			if (!(*valuesMapPtr)["Mileage"].empty())			Mileage = std::stoi((*valuesMapPtr)["Mileage"]);
			if (!(*valuesMapPtr)["MinRentPeriod"].empty())		MinRentPeriod = std::stoi((*valuesMapPtr)["MinRentPeriod"]);
			if (!(*valuesMapPtr)["MaxRentPeriod"].empty())		MaxRentPeriod = std::stoi((*valuesMapPtr)["MaxRentPeriod"]);
			if (!(*valuesMapPtr)["DayRentPrice"].empty())		DayRentPrice = std::stod((*valuesMapPtr)["DayRentPrice"]);

			YB_Car* car = new YB_Car();
			car->Id = Id;
			car->Make = Make;
			car->Model = Model;
			car->Year = Year;
			car->Mileage = Mileage;
			car->IsAvailable = IsAvailable;
			car->MinRentPeriod = MinRentPeriod;
			car->MaxRentPeriod = MaxRentPeriod;
			car->DayRentPrice = DayRentPrice;

			bool result = carManagerPtr->UpdateCar(car);
			if (result) {
				windowPtr->PopPrompt("The car has been successfully updated!", YBConsoleViews::ADMIN_MAIN_VIEW.c_str());
			}
			else
			{
				windowPtr->PopPrompt("There is some issue to add your car information.", nullptr);
			}
		}

	};

}

