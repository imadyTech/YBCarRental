#pragma once
#include "YB_User.h"
#include "YB_Rent.h"
#include "YB_RentPersistor.h"
#include <vector>

using namespace std;

namespace YBCarRental
{
	class YB_RentManager
	{
		YB_RentManager();

		static bool PlaceOrder(YB_User userId, int carId, tm startDate, int days);
		static bool ApproveOrder(YB_Rent rentalOrder);
		static bool RejectOrder(YB_Rent rentalOrder);
		static bool ApproveOrder(int orderId);
		static bool RejectOrder(int orderId);
	};
}