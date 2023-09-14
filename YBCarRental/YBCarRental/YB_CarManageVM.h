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

		void					onViewForwarded(YB_DataBasis* fromData)		override
		{
			this->principalObject = dynamic_cast<YB_Car*>(fromData);
		};
	};

}

