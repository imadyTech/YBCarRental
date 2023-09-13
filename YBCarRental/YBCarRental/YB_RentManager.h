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

		bool PlaceOrder(int userId, int carId, tm startDate, int days);
		bool ApproveOrder(YB_Rent rentalOrder);
		bool RejectOrder(YB_Rent rentalOrder);
		bool ApproveOrder(int orderId);
		bool RejectOrder(int orderId);

	private:
	};
}

#endif YB_RentManager_H