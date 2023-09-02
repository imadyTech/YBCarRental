#ifndef YB_RentManager_H
#define YB_RentManager_H

#include "YB_User.h"
#include "YB_Rent.h"
#include "YB_RentPersistor.h"
#include "YB_ManagerBasis.h"
#include <vector>

using namespace std;

namespace YBCarRental
{
	class YB_RentManager : public YB_ManagerBasis<YB_Rent>
	{
	public:
		YB_RentManager() : YB_ManagerBasis<YB_Rent>() {};
		YB_RentManager(string url) : YB_ManagerBasis<YB_Rent>(url) {};

		static bool PlaceOrder(YB_User userId, int carId, tm startDate, int days);
		static bool ApproveOrder(YB_Rent rentalOrder);
		static bool RejectOrder(YB_Rent rentalOrder);
		static bool ApproveOrder(int orderId);
		static bool RejectOrder(int orderId);
	};
}

#endif YB_RentManager_H