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
	//118 YB_CarDeleteVm- ListView
	class YB_CarDeleteVm : public YB_ViewModelBasis<YB_Car>
	{
	public:
		YB_CarDeleteVm (YBConsoleViews::YB_Window* windowPtr) {
			this->dataManagerPtr = YB_ManagerFactory::CarMgr;
		}

		void					onViewForwarded(YB_DataBasis* fromData)		override
		{
			this->principalObject = dynamic_cast<YB_Car*>(fromData);
		};

		void					onSubmit(map<string, string>* valuesMapPtr)				override
		{
			bool deleteResult = dynamic_cast<YB_CarManager*>( this->dataManagerPtr )->DeleteCar(this->principalObject);

			//if (deleteResult)
			//	windowPtr->Goto("UserMenu");
			//else if (deleteResult)
			//	windowPtr->Goto("AdminMenu");
		};

	};

}

